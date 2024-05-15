cmake_minimum_required(VERSION 3.27)
project(c_dataframe_ndouga_rakotoarinia_e C)

set(CMAKE_C_STANDARD 11)

add_executable(c_dataframe_ndouga_rakotoarinia_e main.c
        column.h
        column.c
        main.c
        cdataframe.h
        cdataframe.c
        liste.h
        liste.c
        sort.h
        sort.c)
