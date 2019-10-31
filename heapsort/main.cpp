#include <iostream>

using keytype = int;
using index_i = int;

class heap {
public:
    int heapsize;
    keytype* arr;

    heap(keytype _arr[], int _heapsize){
        heapsize = _heapsize;
        arr = new keytype[heapsize];
        memcpy(arr, _arr, heapsize*sizeof(keytype));
    };
};

/*
 * parent key 제 위치 찾아주기
 * @param   heap& heap class
 * @param   index_i 시작 parent 위치
 */
void siftdown(heap& h, index_i i){
    index_i parent, largerchild;
    keytype siftkey;
    bool spotfound;

    siftkey = h.arr[i];
    parent = i;         // root of heap
    spotfound = false;

    while(2*parent < h.heapsize && !spotfound){
        // largerchild = parent's child with larger key
        if(2*parent < h.heapsize && h.arr[2*parent] < h.arr[2*parent+1]){
            largerchild = 2*parent+1;
        }
        else{
            largerchild = 2*parent;
        }

        if (siftkey < h.arr[largerchild]){
            h.arr[parent] = h.arr[largerchild];
            parent = largerchild;
        }
        else{
            spotfound = true;
        }
    }
    h.arr[parent] = siftkey;
}

/*
 * root key 빼고 bottom node root로 올린 후 siftdown
 * @param   heap& heap class
 * @return  keytype 빼낸 키값
 */
keytype root(heap& h){
    keytype keyout;

    keyout = h.arr[0];              // root key
    h.arr[0] = h.arr[h.heapsize-1];   // move bottom to root
    h.heapsize = h.heapsize-1;      // delete bottom node
    siftdown(h, 0);

    return keyout;
}

/*
 * heap 배열 전체 빠질때까지 root key 빼내기
 * @param int size
 * @param heap& heap class
 * @param heap 배열
 */
void removekeys(int n, heap& h, keytype arr[]){
    index_i i;
    for (i = n; i >= 1; i--) {
        arr[i] = root(h);
        printf("%d\n", arr[i]);
    }
}

/*
 * heap 배열로 만들기
 * @param int size
 * @param heap& heap class
 */
void makeheap(int n, heap& h){
    index_i i;

    h.heapsize = n;
    for (i = n/2; i >= 0 ; i--) {
        siftdown(h, i);
    }
}

void heapsort(int n, heap& h){
    makeheap(n, h);
    removekeys(n, h, h.arr);
}


int main() {
    int heapsize = 10;
    keytype n[] = {30,25,20,18,12,19,17,16,14,11};

    heap h(n, heapsize);

    heapsort(heapsize, h);

    return 0;
}

