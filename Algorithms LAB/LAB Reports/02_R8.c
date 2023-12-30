#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    char data;
    int freq;
    struct Node *left, *right;
};

struct Node* newNode(char data, int freq) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}


void minHeapify(struct Node** minHeap, int size, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && minHeap[left]->freq < minHeap[smallest]->freq)
        smallest = left;

    if (right < size && minHeap[right]->freq < minHeap[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        struct Node* temp = minHeap[idx];
        minHeap[idx] = minHeap[smallest];
        minHeap[smallest] = temp;

        minHeapify(minHeap, size, smallest);
    }
}


void buildMinHeap(struct Node** minHeap, int size) {
    int i = (size - 1) / 2;
    for (; i >= 0; i--)
        minHeapify(minHeap, size, i);
}

struct Node* extractMin(struct Node** minHeap, int* size) {
    struct Node* temp = minHeap[0];
    minHeap[0] = minHeap[(*size) - 1];
    (*size)--;
    minHeapify(minHeap, *size, 0);
    return temp;
}

void insertMinHeap(struct Node** minHeap, int* size, struct Node* node) {
    (*size)++;
    int i = *size - 1;
    while (i > 0 && node->freq < minHeap[(i - 1) / 2]->freq) {
        minHeap[i] = minHeap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap[i] = node;
}


struct Node* buildHuffmanTree(char data[], int freq[], int size) {
    struct Node *left, *right, *top;

    
    struct Node** minHeap = (struct Node**)malloc(size * sizeof(struct Node*));
    for (int i = 0; i < size; i++)
        minHeap[i] = newNode(data[i], freq[i]);

    int heapSize = size;
    buildMinHeap(minHeap, heapSize);

    while (heapSize > 1) {
        left = extractMin(minHeap, &heapSize);
        right = extractMin(minHeap, &heapSize);

        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, &heapSize, top);
    }

    return minHeap[0];
}

void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}


float calculateAverageCodeLength(struct Node* root, int depth) {
    if (!root)
        return 0;

    if (!(root->left) && !(root->right))
        return depth * root->freq;

    return calculateAverageCodeLength(root->left, depth + 1) +
           calculateAverageCodeLength(root->right, depth + 1);
}


int calculateEncodedLength(struct Node* root, int depth) {
    if (!root)
        return 0;

    if (!(root->left) && !(root->right))
        return depth * root->freq;

    return calculateEncodedLength(root->left, depth + 1) +
           calculateEncodedLength(root->right, depth + 1);
}

int main() {
    char data[] = {'A', 'E', 'I', 'O', 'U', 'S', 'T'};
    int freq[] = {10, 15, 12, 3, 4, 13, 1};
    int size = sizeof(data) / sizeof(data[0]);

    struct Node* root = buildHuffmanTree(data, freq, size);


    printf("Huffman Codes:\n");
    int arr[100];
    printCodes(root, arr, 0);

    float averageCodeLength = calculateAverageCodeLength(root, 0) / (float)size;
    printf("\nAverage Code Length: %.2f\n", averageCodeLength);

   
    int encodedLength = calculateEncodedLength(root, 0);
    printf("Length of Huffman Encoded Message: %d bits\n", encodedLength);

    return 0;
}