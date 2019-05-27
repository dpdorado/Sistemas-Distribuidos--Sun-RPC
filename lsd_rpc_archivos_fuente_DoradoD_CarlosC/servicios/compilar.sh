#!/bin/bash

echo "Iniciar secion"

cd inicio_sesion

make -f mks

cd ..

echo "Jefe Departamento"

cd jefe_departamento

make -f mks

cd ..

echo "Estudiante- Director"

cd estudiante_director

make -f mks

cd ..

echo "Evaluador"

cd evaluador

make -f mks

cd ..
