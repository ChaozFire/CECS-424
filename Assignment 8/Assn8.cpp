#include <iostream>
#include <stdlib.h>
using namespace std;

int** make_matrix(int row, int column, bool asc) {
  int** matrix;
  matrix = new int*[row];
  int counter;
  if(asc) {
    counter = 1;
  } else {
    counter = row*column;
  }

  for(int i = 0; i < row; i++) {
    *(matrix+i) = new int[column];
  }
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < column; j++) {
      if(asc) {
        *(*(matrix+i)+j)=counter;
        counter++;
      }
      else {
        *(*(matrix+i)+j)=counter;
        counter--;
      }
    }
  }
  return matrix;
}

int** mult_matrix(int** m1, int** m2, int row1, int column1, int row2, int column2) {
  int** product;
  product = new int*[row1];

  for(int i = 0; i < row1; i++) {
    *(product+i) = new int[column2];
  }

  for(int i = 0; i < row1; i++) {
    for(int j = 0; j < column2; j++) {
      //*(*(product+i)+j)
      int count = 0;
      int sum = 0;
      while(count < column1) {
        sum = sum + *(*(m1+i)+count)**(*(m2+count)+j);
        count++;
      }
      *(*(product+i)+j) = sum;
    }
  }
  return product;
}

void print_matrix(int** matrix, int row, int column) {
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < column; j++) {
      cout << *(*(matrix+i)+j) << " ";
    }
    cout << endl;
  }
}

int main(int argc, char** argv) {
  int r1 = atoi(argv[1]);
  int c1 = atoi(argv[2]);
  int r2 = atoi(argv[3]);
  int c2 = atoi(argv[4]);

  int** m1;
  int** m2;
  int** product;
  m1 = make_matrix(r1,c1,true);
  m2 = make_matrix(r2,c2,false);

  cout << "Matrix 1" << endl;
  print_matrix(m1,r1,c1);
  cout << "Matrix 2" << endl;
  print_matrix(m2,r2,c2);
  product = mult_matrix(m1, m2, r1, c1, r2, c2);
  cout << "Matrix 1 * Matrix 2" << endl;
  print_matrix(product, r1, c2);
  return 0;
}
