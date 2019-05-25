#!/bin/bash

./inicio_sesion/servidor_is localhost &

./jefe_departamento/servidor_jd localhost &

./estudiante_director/servidor_ed localhost &

./evaluador/servidor_e localhost &


