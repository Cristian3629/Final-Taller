//
// Created by darius on 12/07/17.
//

/*
 * Ejemplo de como ejecutar una funcion/functor en un hilo separado en C++
 *
 * Se ejecutan varios functors en paralelo en donde el objeto thread tiene una referencia
 * al objeto functor (usamos composicion)
 *
 * Compilar con g++ -std=c++11 -pedantic 02_is_prime_parallel_by_composition.cpp -pthread
 *
 * */

#include <iostream>
#include <vector>
#include <thread>

#define N 10

class IsPrime {
    private:
        unsigned int n;
        bool &result;
    public:
        IsPrime(unsigned int n, bool &result) : n(n), result(result) {}

        void operator()() {
            for (unsigned int i = 2; i < n; ++i) {
                if (n % i == 0) {
                    result = false;
                    return;
                }
            }

            result = true;
        }
};



int maine() {
    unsigned int nums[N] = {0, 1, 2, 3, 4, 5, 13, 132130891, 132130891, 132130871};
    bool results[N];

    std::vector<std::thread> threads;

    for (int i = 0; i < N; ++i) {
        // Aca es donde usamos composicion donde "std::thread tiene un IsPrime"
        // El operator call del functor se ejecutara en el hilo lanzado por el constructor
        // del objeto std::thread
        threads.push_back(std::thread (IsPrime(nums[i], results[i])));//0.10: std thread recibe como argumento un código ejecutable, sea una función, sea un método o sea un objeto que se comporta como una función (osea un functor). En cuanto instanciamos el objeto thread, automáticamente el ejecutable IsPrime se va a ejecutar directamente en otro hilo.
    }

    /* ************************************** */
    /* Ahora: Todos los hilos estan corriendo */
    /* ************************************** */

    // Esperamos a que cada hilo termine.
    // Cada join bloqueara al hilo llamante (main) hasta que el hilo
    // sobre el cual se le hace join (threads[i]) termine
    for (int i = 0; i < N; ++i) {
        threads[i].join();
    }

    /* ********************************************************************** */
    /* Ahora: Todos los hilos terminaron y sus recursos limpiados con el join */
    /* ********************************************************************** */

    for (int i = 0; i < N; ++i) {
        std::cout << results[i] << " ";
    }
    std::cout << "\n";

    return 0;
}

