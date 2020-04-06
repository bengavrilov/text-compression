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

    // huffman code
    char code[16];

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
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]); 
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

void storeCode (struct MinHeapNode* node, int arr[], int n) {
    
    for (int i = 0; i < n; i++) {
        sprintf(node->code + i, "%d", arr[i]);
    }
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

void storeCodes(struct MinHeapNode *root, int *arr, int top) {
    if (root->left) {
        arr[top] = 0;
        storeCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        storeCodes(root->right, arr, top + 1);
    }
    
    if (isLeaf(root)) {
        storeCode(root, arr, top);
    }
}

void traverseToNode(FILE *outputFile, char character, struct MinHeapNode *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        traverseToNode(outputFile, character, root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        traverseToNode(outputFile, character, root->right, arr, top + 1);
    }
    if (root->data == character) {
        fprintf(outputFile, "%d", atoi(root->code));
    }
}

struct MinHeapNode* applyCompression(char data[], int freq[], int size) {
    printf("test checkpoint1\n");

    // Step 1: Call buildHuffmanTree and store root
    struct MinHeapNode *root = buildHuffmanTree(data, freq, size);
    printf("test checkpoint2\n");
    // Step 2: Call storeCodes with appropriate parameters
    int *arr = malloc(sizeof(int) * 100);
    int top = 0;
    storeCodes(root, arr, top);
    return root;
}

void resetArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }
}

/*
void writeBit (int bit, FILE *outputFile, unsigned char *bitBuffer, int *currentBit) {
    if (bit) {
        *bitBuffer |= (1<<*currentBit);
    }

    *currentBit++;
    if (*currentBit == 8) {
        fwrite(bitBuffer, 1, 1, outputFile);
        *currentBit = 0;
        *bitBuffer = 0;
    }
}
*/

int main (int argc, char **argv) {

    char data[2500];
    int freq[2500];
    int currentChar = 0;
    char input[2000];
    int charFound;
    // Step 1: Traverse txt file and store each unique character in data array
    //         and store number of occurences in freq array
    FILE *textFile;
    int error;

    textFile = fopen(argv[1], "r");
    if (textFile == NULL) {
        fprintf(stderr, "Error opening file\n");
    }

    while (fscanf(textFile, "%100s", input) != EOF) {
        for (int i = 0; i < strlen(input); i ++) {
            charFound = -1;
            for (int y = 0; y < currentChar; y ++) {
                if (data[y] == input[i]) {
                    freq[y]++;
                    charFound = 1;
                    break;
                }
            }

            if (charFound == -1) {
                data[currentChar] = input[i];
                freq[currentChar]++;
                currentChar++;
            }
        }
    }

    error = fclose(textFile);
    if (error != 0) {
        fprintf(stderr, "fclose failed\n");
    }
    
    printf("test checkpoint\n");

    // Step 3: Call apply compression with appropriate parameters
    struct MinHeapNode *root = applyCompression(data, freq, currentChar);

    int array[100] = {0};
    int top = 0;
    
    // Step 4: Reiterate over input text and output respective codes
    FILE *textFile2;
    int error2;
    
    //int *currentBit = malloc(sizeof(int));
    //unsigned char *bitBuffer = malloc(sizeof(unsigned char));

    FILE *outputFile;
    int error3;

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening writing file\n");
    }

    textFile2 = fopen(argv[1], "r");
    if (textFile2 == NULL) {
        fprintf(stderr, "Error opening file2\n");
    }

    while (fscanf(textFile2, "%100s", input) != EOF) {
        for (int i = 0; i < strlen(input); i ++) {
            resetArray(array, 100);
            top = 0;
            traverseToNode(outputFile, input[i], root, array, top);

        }
    }

    error3 = fclose(outputFile);
    if (error3 != 0) {
        fprintf(stderr, "fclose for writing file failed\n");
    }

    error2 = fclose(textFile2);
    if (error2 != 0) {
        fprintf(stderr, "fclose failed2\n");
    }

    return 0;
}