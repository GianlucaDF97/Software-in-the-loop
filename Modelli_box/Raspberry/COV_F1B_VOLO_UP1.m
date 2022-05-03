%% Process noise covariance Filtro 1B
%UPDATE UNO
Q1B = [    1.4e-14;...%Lat 
                 1.5e-14;...%Long

         0.01;...%h
         
      
               0.03;...%vn 0.2 
               0.03;...%ve  0.3
               
            7.5e-06;...%vd 
      



       0.045*1e-04;...an
       0.045*1e-04;...ae
       0.045*1e-04;...ad



         1.15*5.5e-07;...%p ex 1.2
         1.15*5.5e-07;...q
         1.15*5.5e-07;...r
         

       0;...%baccx
       0;...%baccy
       0;...%baccz
%       
      0;...%bp
      0;...%bq
      0];  %br
  
  
%% mesurement noise covariance

R1B =[     1e-13;...%Lat
                 1e-13;...%Long
         
       0.06;...%h(press)
      
     0.7;...%vnord
      0.7;...%vest
      
      1.9943e-04;...ax
      7.3240e-05;...ay
      1.0650e-04;...az
    
%    
          5.0234e-07;...%p
          5.1618e-07;...q
          5.5986e-07;...r
             ]; 

