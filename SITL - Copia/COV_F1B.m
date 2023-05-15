
% il 07/03/22 D' alessio, Di micco, Viscione e Perfetti hanno modificato
% questo file seguendo le indicazioni del dottor D' antuono

%% Process noise covariance Filtro 1

Q1B = [    2e-15;...%Lat 
    2e-15;...%Long

    0.001;...%h

    40e-03;...%vn5e-02
    40e-03;...%ve


    5e-05;...%vd caso limite loiter  5e-04




    %        2e-05;...%an 05
    %        2e-05;...%ae
    %        2e-03;...%ad


    %         1.2*3.0420e-05;...%an
    %         1.2*3.0420e-05;...%ae
    %         1.2*3.0420e-05;...%ad

    1.9943e-04;...ax
    7.3240e-05;...ay
    1.0650e-04;...az

    8.8826*3e-07;...%p
    8.8826*3e-07;...q
    8.8826*4e-06;...r

    6e-20;...%baccx
    6e-20;...%baccy
    6e-20;...%baccz

    6e-15;...%bp
    6e-15;...%bq
    6e-15];  %br

  
  
%% mesurement noise covariance

R1B = [     2e-14;...%Lat
            2e-14;...%Long
         
            0.1444;...%h(press)
      
            0.2;...%vnord0.001 1
            0.2;...%vest0.001 1
      
% il 07/03/22 è stato cambiato seguendo le indicazioni del dottor d' antuono  prima i valori erano quelli commentati

            1.486e-04;... %1.9943e-04;...ax
            9.403e-05;... %7.3240e-05;...ay
            1.648e-04;... %1.0650e-04;...az
      
       
            2.934e-4;... %8.8826e-09;...%p
            2.887e-05;... %8.8826e-09;...q
            3.258e-3;... %8.8826e-09;...r
             ]; 
