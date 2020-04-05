/*
 * Created by Ben Gavrilov on April 5, 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MinHeapNode {

    // One of the chars in the input
    char data;

    // Frequency of the char
    unsigned freq;

    // Left child of this node
    struct MinHeapNode *left;
    // Right child of thise node
    struct MinHeapNode *right;
};

struct MinHeap {

    // Current size of min heap
    unsigned size;

    // capacity of min heap
    unsigned capacity;

    // Array of minheap node pointers
    struct MinHeapNode **array;
};

struct MinHeapNode* newNode(char data, unsigned freq) {
    struct MinHeapNode *temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));

    temp->left = temp->right;
    temp->data = data;
    temp->freq = freq;

    return temp;
}

struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap *minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));

    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));

    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b) { 
    struct MinHeapNode* t = *a; 
    *a = *b; 
    *b = t; 
}

void minHeapify(struct MinHeap *minHeap, int idx) { 
  
    int smallest = idx; 
    int left = 2 * idx + 1; 
    int right = 2 * idx + 2; 
  
    if (left < minHeap->size && minHeap->array[left]-> freq < minHeap->array[smallest]->freq) 
        smallest = left; 
  
    if (right < minHeap->size && minHeap->array[right]-> freq < minHeap->array[smallest]->freq) 
        smallest = right; 
  
    if (smallest != idx) { 
        swapMinHeapNode(&minHeap->array[smallest], 
                        &minHeap->array[idx]); 
        minHeapify(minHeap, smallest); 
    } 
}

int isSizeOne(struct MinHeap* minHeap) { 
  
    return (minHeap->size == 1); 
}

struct MinHeapNode* extractMin(struct MinHeap *minHeap) { 
  
    struct MinHeapNode* temp = minHeap->array[0]; 
    minHeap->array[0] = minHeap->array[minHeap->size - 1]; 
  
    --minHeap->size; 
    minHeapify(minHeap, 0); 
  
    return temp; 
} 

void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode) { 
  
    ++minHeap->size; 
    int i = minHeap->size - 1; 
  
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) { 
  
        minHeap->array[i] = minHeap->array[(i - 1) / 2]; 
        i = (i - 1) / 2; 
    } 
  
    minHeap->array[i] = minHeapNode; 
}

void buildMinHeap(struct MinHeap *minHeap) { 
  
    int n = minHeap->size - 1; 
    int i; 
  
    for (i = (n - 1) / 2; i >= 0; --i) 
        minHeapify(minHeap, i); 
} 

int isLeaf(struct MinHeapNode *root) { 
  
    return !(root->left) && !(root->right); 
}

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) { 
  
    struct MinHeap* minHeap = createMinHeap(size); 
  
    for (int i = 0; i < size; ++i) 
        minHeap->array[i] = newNode(data[i], freq[i]); 
  
    minHeap->size = size; 
    buildMinHeap(minHeap); 
  
    return minHeap; 
}

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) { 
    struct MinHeapNode *left;
    struct MinHeapNode *right;
    struct MinHeapNode *top; 
  
    // Step 1: Create a min heap of capacity 
    // equal to size.  Initially, there are 
    // modes equal to size. 
    struct MinHeap *minHeap = createAndBuildMinHeap(data, freq, size); 
  
    // Iterate while size of heap doesn't become 1 
    while (!isSizeOne(minHeap)) { 
  
        // Step 2: Extract the two minimum 
        // freq items from min heap 
        left = extractMin(minHeap); 
        right = extractMin(minHeap); 
  
        // Step 3:  Create a new internal 
        // node with frequency equal to the 
        // sum of the two nodes frequencies. 
        // Make the two extracted node as 
        // left and right children of this new node. 
        // Add this node to the min heap 
        // '$' is a special value for internal nodes, not used 
        top = newNode('$', left->freq + right->freq); 
  
        top->left = left; 
        top->right = right; 
  
        insertMinHeap(minHeap, top); 
    } 
  
    // Step 4: The remaining node is the 
    // root node and the tree is complete. 
    return extractMin(minHeap); 
}