@echo off
set MATLAB=C:\Program Files\MATLAB\R2020b
"%MATLAB%\bin\win64\gmake" -f v2022_Modello_SITL_AENEA_2020b.mk  OPTS="-DTID01EQ=1"
