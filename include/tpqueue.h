// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T arr[100];
    int fp, sp;
 public:
     TPQueue() : fp(0), sp(0) {}
    void push(T x) {
            int i = sp++;
            while ((--i >= fp) && (arr[i % size].prior < x.prior)) {
                arr[(i + 1) % size] = arr[i % size];
            }
            arr[(i + 1) % size] = x;
        }
    T pop() {
        return (arr[(fp++) % size]);
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
