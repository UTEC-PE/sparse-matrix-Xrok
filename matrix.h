#ifndef MATRIX_H
#define MATRIX_H

#include "node.h"

using namespace std;

template <typename T>
class Matrix { 
    public:
        Node<T>* hRows;
        Node<T>* hColumns;
        int columns;
        int rows;

    public:
        Matrix();
        Matrix(int sizeX, int sizeY){
            rows = sizeX; 
            columns = sizeY;
            hRows = new Node<T>();
            hColumns = new Node<T>();

            hRows->down = new Node <T>(0);

            Node<T>* temp= hRows->down;
            for (int i = 1; i < sizeX; ++i)
            {
             temp->down= new Node <T>(i);
             temp=temp->down;

            }

            hColumns->next = new Node <T>(0);
            temp= hColumns->next;

            for (int i = 1; i < sizeY; ++i)
            {
                temp->next = new Node<T>(i);
                temp=temp->next;
            }
        };

        void set(int x, int y, T data){

            Node<T>* Rtemp = this->hRows;

            for (int i = 0; i < x; ++i)
            {
                Rtemp=Rtemp->down;
            }

            if (Rtemp->next)
            {
                while((Rtemp->next->x < x) && Rtemp->next){
                    Rtemp=Rtemp->next;
                }
            }
    
            Node<T>* Ctemp = this->hColumns;

           
            for (int i = 0; i < y; ++i)
            {
                Ctemp=Ctemp->next;
            }
            
            if (Ctemp->down)
            {
                while((Ctemp->down->y < y) && Ctemp->down){
                    Ctemp=Ctemp->down;
                }
            }
            Node<T>* tempSet = new Node<T>(Rtemp->next,Ctemp->down,x,y,data);
            Rtemp->next=tempSet;
            Ctemp->down=tempSet;
        };

        T operator()(int x, int y){
            Node<T>* temp =hColumns;
            for (int i = 0; i <y ; ++i)
            {
                temp=temp->next;                
            }
            if (temp->down)
            {
                while(temp->down){
                    if (temp->down->x == x)
                    {
                        return temp->down->data;
                    }
                    temp=temp->down;
                }
                return 0;
            }else{
                return 0;
            }
        };


        Matrix<T> operator*(Matrix<T> other){

            if(this->columns == other.rows){
                Matrix<int> resultado(rows,other.columns);
            
                        for (int i = 0; i < rows; ++i)
                        {
                            int temp=0;
                            
                            for (int j = 0; j < other.columns; ++j)
                            {
                                for (int k = 0; k < columns; ++k)
                                {
                                    
                                    temp += (((*this)(i,k))*((other)(k,j)));
                                }
                                if (temp)
                                {
                                    resultado.set(i,j,temp);
                                }
                            }
                            
                        }
                        return resultado;
            }else
            {
                cout<<"Incorrecto tamaño de las matrices."<<endl;
                return *this;
            }
        };

        Matrix<T> operator*(T scalar){

            Matrix<int> resultado(rows,columns);
            for (int i = 0; i <rows ; ++i)
            {
                for (int j = 0; j <columns ; ++j)
                {
                    if ((*this)(i,j))
                    {
                        resultado.set(i,j,(((*this)(i,j)*scalar)));
                    }
                }
            }
            return resultado;
        };


        Matrix<T> operator+(Matrix<T> other){

          if(this->columns == other.columns && this->rows == other.rows)
            {  
                Matrix<int> resultado(rows,columns);
          
                      for (int i = 0; i < rows; ++i)
                      {
                          for (int j = 0; j < columns; ++j)
                          {
                           if ((*this)(i,j)+(other)(i,j))
                           {
                              resultado.set(i,j,((*this)(i,j)+(other)(i,j)));
                           }
                          }
                      }
                      return resultado;
            }else
            {
                cout<<"Incorrecto tamaño de las matrices."<<endl;
                return *this;
            }
        };

        Matrix<T> operator-(Matrix<T> other){
            
            if(this->columns == other.columns && this->rows == other.rows)
            {
                Matrix<int> resultado(rows,columns);
               
                for (int i = 0; i < rows; ++i)
                {
                    for (int j = 0; j < columns; ++j)
                    {
                        if ((*this)(i,j)-(other)(i,j))
                        {
                           resultado.set(i,j,((*this)(i,j)-(other)(i,j)));
                        }              
                    }
                }
                return resultado;
            }else{
                cout<<"Incorrecto tamaño de las matrices."<<endl;
                return *this;
            }
        };

        Matrix<T> transposed(){

            Matrix<int> resultado(columns,rows);

            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < columns; ++j)
                {
                 if ((*this)(i,j))
                 {
                    resultado.set(j,i,(*this)(i,j));
                 }
                }
            }
            return resultado;
        };
        Matrix<T> operator=(Matrix<T> other){
            if(this->columns == other.columns && this->rows == other.rows)
            {
                for (int i = 0; i < rows; ++i)
                {
                    for (int j = 0; j < columns; ++j)
                    {
                        if ((other)(i,j))
                        {

                            this->set(i,j,(other)(i,j));
                        }
                    }
                }
                return *this;
            }else{
                cout<<"Incorrecto tamaño de las matrices."<<endl;
                return *this;
            }
        };


        void print(){
            for (int x = 0; x < rows; ++x)
            {
                for (int y = 0; y < columns; ++y)
                {
                    int d = (*this)(x,y);
                    cout<<d<<" \t";
                }
                cout<<endl;
            }
        };

        ~Matrix(){};
};

#endif