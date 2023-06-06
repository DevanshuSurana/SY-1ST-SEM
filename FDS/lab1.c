#include<stdio.h>

void read_matrix(int mat[10][10],int  rowc, int  colc, int num)
{
  int c,r;

  printf("Enter values for matrix %d \n", num);
  
  for(r=0; r<rowc; r++)
  {
      for(c=0; c<colc; c++)
      {
          printf ("Enter Value [%d] [%d]:",r,c);
          scanf ("%d",&mat[r][c]);
      }
  }
}

void addition (int mat1[10][10],int mat2[10][10],int mat3[10][10],int rowc, int colc)
{
    int r,c;
    for (r=0;r<rowc;r++)
    {
        for (c=0;c<colc;c++)
        {
            mat3[r][c]=mat1[r][c]+mat2[r][c];
        }
    }
}

void subtraction (int mat1[10][10],int mat2[10][10],int mat3[10][10],int rowc, int colc)
{
    int r,c;
    for (r=0;r<rowc;r++)
    {
        for (c=0;c<colc;c++)
        {
            mat3[r][c]=mat2[r][c]-mat1[r][c];
        }
    }
}

void multiplication (int mat1[10][10],int mat2[10][10],int mat3[10][10],int rowc, int colc)
{
    int r,c,k;
    for (r=0;r<rowc;r++)
    {
        for (c=0;c<colc;c++)
        {
            mat3[r][c]=0;
            
            for (k=0;k<colc;k++)
            {
                mat3[r][c]+=mat1[r][k]*mat2[k][c];
            }
        }
    }
}

void transpose (int mat1[10][10], int mat2[10][10], int mat3[10][10],int rowc, int colc)
{
    int r,c;
    for (r=0;r<rowc;r++)
    {
        for (c=0;c<colc;c++)
        {
        mat3[c][r]=mat1[r][c];
        }
    }
    printf ("\n");
    for (r=0;r<rowc;r++)
    {
        for (c=0;c<colc;c++)
        {
        mat3[c][r]=mat2[r][c];
        }
    }
}

int main ()
{
  int row,col,r,c;
  int mat1[10][10], mat2[10][10], mat3[10][10];

  printf ("Enter number of rows of matrix :");
  scanf ("%d", &row);
  printf ("Enter number of columns of matrix :");
  scanf ("%d", &col);
    
  read_matrix (mat1,row,col,1);

  for (r=0;r<row;r++)
  {
      for (c=0;c<col;c++)
      {
          printf ("%d ",mat1[r][c]);
      }
      printf ("\n");
  }

  
  read_matrix (mat2,row,col,2);
  for (r=0;r<row;r++)
  {
      for (c=0;c<col;c++)
      {
          printf ("%d ", mat2[r][c]);
      }
      printf ("\n");
  }
  
  char inp_operation;
  printf ("Available operations: \n");
  printf ("1.Addition \n");
  printf ("2.Subtraction \n");
  printf ("3.Multiplication \n");
  printf ("4.Transpose \n");
  printf ("Enter choice: ");
  scanf (" %c", &inp_operation);
  
  switch (inp_operation)
  {
      case '1':
      
         addition (mat1, mat2, mat3, row, col);
         printf ("Sum is: \n");
         for (r=0;r<row;r++)
         {
             for (c=0;c<col;c++)
             {
                  printf ("%d ", mat3[r][c]);
             }
             printf ("\n");
         }
         break;
         
       case '2':
          
         subtraction (mat1,mat2,mat3,row,col);
         printf ("Difference is: \n");
         for (r=0;r<row;r++)
         {
             for (c=0;c<col;c++)
             {
                 printf ("%d ", mat3[r][c]);
             }
             printf ("\n");
         }
         break;
    
       case '3':
       
         multiplication (mat1,mat2,mat3,row,col);
         printf ("Product is: \n");
         for (r=0; r<row;r++)
         {
             for (c=0;c<col;c++)
             {
                 printf ("%d ", mat3[r][c]);
             }
             printf ("\n");
         }
         break;
         
       case '4':
         
         transpose (mat1,mat2,mat3,row,col);
         printf ("transpose of matrix: \n");
         for (r=0; r<row;r++)
         {
             for (c=0;c<col;c++)
             {
                 printf ("%d ", mat3[r][c]);
             }
             printf ("\n");
         }
         printf ("\n");
         for (r=0; r<row;r++)
         {
             for (c=0;c<col;c++)
             {
                 printf ("%d ", mat3[r][c]);
             }
             printf ("\n");
         }
         
         break;
         
       
  }
}
