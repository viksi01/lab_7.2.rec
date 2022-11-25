#include <iostream>
#include <iomanip>
#include <time.h>


using namespace std;


void Create(int** a, const int HIGH, const int LOW, const int rowCount, const int colCount, int i, int j)
{
    {
        a[i][j] = LOW + rand() % (HIGH - LOW + 1);
        if (j < colCount - 1)
            Create(a, HIGH, LOW, rowCount, colCount, i, j + 1);
        else
            if (i < rowCount - 1)
                Create(a, HIGH, LOW, rowCount, colCount, i + 1, 0);
    }
}

  void Print(int** a, const int rowCount, const int colCount, int i, int j)
  {
        cout << a[i][j] << "\t";
        if (j < colCount - 1)
            Print(a, rowCount, colCount, i, j + 1);
        else

            if (i < rowCount - 1)
            {
                cout << "\n";
                Print(a, rowCount, colCount, i + 1, 0);
            }

            else
                cout << "\n" << "\n" << "\n";
  }

    
  void Change(int** a, int& imax, int& jmax, int& i, int& j, const int colCount)
  {
      int tmp = 0;
      tmp = a[imax][jmax];
      a[imax][jmax] = a[i][i];
      a[i][i] = tmp;
      if (j < colCount - 1)
          Change(a, imax, jmax, i, j, colCount);
  }

  int Max(int** a, const int rowCount, const int colCount, int& max, int& imax_1, int& jmax_1, int i, int j)
  {
      if (a[i][j] >= max)
      {
          max = a[i][j];
          jmax_1 = j;
          imax_1 = i;
      }
      if (j < colCount - 1)
          Max(a, rowCount, colCount, max, imax_1, jmax_1, i, j + 1);
      else
          if (i < rowCount - 1)
              Max(a, rowCount, colCount, max, imax_1, jmax_1, i + 1, 0);
          else
              return max;
  }


  void Replace(int** a, const int rowCount, const int colCount, int max, int& jmax, int& imax, int j, int i, bool b)
  {
      if (i < rowCount)
      {
          if (b)
          {
              max = a[i][0];
              b = false;
          }
          if (i < rowCount)
          {
              if (j < colCount)
              {
                  if (a[i][j] >= max)
                  {
                      max = a[i][j];
                      jmax = j;
                      imax = i;

                  }
                  if (j == colCount - 1)
                  {
                      cout << "a[" << imax << "][" << jmax << "] = " << max << "\t" << "\n";
                      if (a[i][i] != a[imax][jmax])
                      {
                          Change(a, imax, jmax, i, j, colCount);
                      }
                  }
                  Replace(a, rowCount, colCount, max, jmax, imax, j + 1, i, b);
              }
              else
              {
                  bool b = true;
                  Replace(a, rowCount, colCount, max, jmax, imax, 0, i + 1, b);
              }
          }
      }
      else return;
  }

    


int main()
{
    srand(time(NULL));

    const int HIGH = 100;
    const int LOW = 1;
    int rowCount;
    int colCount;
    cout << "Enter the matrix size: "; cin >> rowCount;
    colCount = rowCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];
    int i = 0;
    int j = 0;

    Create(a, HIGH, LOW, rowCount, colCount, i, j);
    Print(a, rowCount, colCount, i, j);
    int max = a[0][0];
    int imax = 0;
    int jmax = 0;
    bool b = false;
    Replace(a, rowCount, colCount, max, jmax, imax, j, i, b);
    Print(a, rowCount, colCount, i, j);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[]a;

    system("pause");
    return 0;
}