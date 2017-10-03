#include <iostream>
#include <fstream>
#include <vector>
#include "dijkstra.hpp"

void OutputMatrix( const std::vector< std::vector<int> > &adj_matrix, int num_elements, std::ofstream &ofs )
{
    for ( int i = 0; i < num_elements; i++ )
    {
        for ( int j = 0; j < num_elements; j++ )
        {
            ofs << adj_matrix[i][j] << " ";
        }  
        ofs << std::endl;          
    }
    ofs << std::endl;

    std::cout << "Verificar resultado em output.txt" << std::endl;
}

void OutputShortestPath( const std::vector<int> &parents, const std::vector< std::vector<int> > &adj_matrix, std::ofstream &ofs )
{
    int sum = 0;
    int distance = 0;
    int size = parents.size();
    ofs << "Initial vertex = 0" << std::endl;
    for ( int i = 1; i < size; i++ )
    {
        for ( int j = i; j != 0; )
        {
            distance += distance + adj_matrix[j][parents[j]];
            j = parents[j];
        }
        ofs << "Distance to " << i << ": " << distance << std::endl;
        distance = 0;
        sum += adj_matrix[i][parents[i]];
    }
    ofs << std::endl << "Total distance: " << sum << std::endl;
}

int main( int argc, char *argv[ ] )
{
    std::string filename;

    if ( argc == 1 )
    {
        filename = "../Test instances/example.txt";
    }
    else
    {
        filename = argv[1];
    }
    
    std::vector< std::vector<int> > adj_matrix;
    int num_elements;

    std::ifstream ifs( filename );
    {
        if ( ifs.is_open() )
        {
            ifs >> num_elements;
            adj_matrix.resize( num_elements, std::vector<int>( num_elements ) );

            for ( int i = 0; i < num_elements-1; i++ )
            {
                for ( int j = i+1; j < num_elements; j++ )
                {
                    ifs >> adj_matrix[i][j];
                    adj_matrix[j][i] = adj_matrix[i][j];
                }            
            }
            ifs.close();
        }
        else
        {
            std::cout << "Arquivo de entrada não encontrado" << std::endl;
            return 0;
        }
    }

    std::vector<Elements> elements( num_elements );
    std::vector<int> parents( Dijkstra( adj_matrix, elements ) );

    std::ofstream ofs( "output.txt" );
    {
        if ( !ofs.is_open() )
        {
           std::cout << "Erro ao criar o arquivo de saída" << std::endl;
          return 0;
        }

        OutputMatrix( adj_matrix, num_elements, ofs );

        OutputShortestPath( parents, adj_matrix, ofs );

        ofs.close();
    }

    return 0;
}
