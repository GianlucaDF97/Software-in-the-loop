
A1=linsys_long.A;
B1=linsys_long.B;
C1=linsys_long.C;
D1=linsys_long.D;
A2=linsys_lat.A;
B2=linsys_lat.B;
C2=linsys_lat.C;
D2=linsys_lat.D;
SYS1=ss(A1,B1,C1,D1);
SYS2=ss(A2,B2,C2,D2);

[V1,D1]=eig(SYS1.A);
[V2,D2]=eig(SYS2.A);

% COMPOSIZIONE DEL SISTEMA LINEARIZZATO DELLA DINAMICA LONGITUDINALE
Alon1=[A1(6,6),A1(6,8),A1(6,4),A1(6,2)];
Alon2=[A1(8,6),A1(8,8),A1(8,4),A1(8,2)];
Alon3=[A1(4,6),A1(4,8),A1(4,4),A1(4,2)];
Alon4=[A1(2,6),A1(2,8),A1(2,4),A1(2,2)];
Alon=[Alon1;Alon2;Alon3;Alon4];

[Vlong,Elong]=eig(Alon);

Blon1=[B1(6,1),B1(6,2)];
Blon2=[B1(8,1),B1(8,2)];
Blon3=[B1(4,1),B1(4,2)];
Blon4=[B1(2,1),B1(2,2)];

Blon=[Blon1;Blon2;Blon3;Blon4];

Clon=diag([1,1,1,1]);

Dlon=zeros(4,2);

SYSlon=ss(Alon,Blon,Clon,Dlon);
figure (1)
pzmap(SYSlon)

lambda_sp=Elong(1,1);
lambda_ph=Elong(3,3);

puls_ph=sqrt(real(lambda_ph)^2+imag(lambda_ph)^2) 
sm_ph=-real(lambda_ph)/puls_ph


puls_sp=sqrt(real(lambda_sp)^2+imag(lambda_sp)^2)
sm_sp=-real(lambda_sp)/puls_sp



% COMPOSIZIONE DEL SISTEMA LINEARIZZATO DELLA DINAMICA LATERODIREZIONALE

Alat1=[A2(8,8),A2(8,4),A2(8,6),A2(8,3),A2(8,1)];
Alat2=[A2(4,8),A2(4,4),A2(4,6),A2(4,3),A2(4,1)];
Alat3=[A2(6,8),A2(6,4),A2(6,6),A2(6,3),A2(6,1)];
Alat4=[A2(3,8),A2(3,4),A2(3,6),A2(3,3),A2(3,1)];
Alat5=[A2(1,8),A2(1,4),A2(1,6),A2(1,3),A2(1,1)];
Alat=[Alat1;Alat2;Alat3;Alat4;Alat5];

[Vlat,Elat]=eig(Alat);

Blat1=[B2(8,1),B2(8,2)];
Blat2=[B2(4,1),B2(4,2)];
Blat3=[B2(6,1),B2(6,2)];
Blat4=[B2(3,1),B2(3,2)];
Blat5=[B2(1,1),B2(1,2)];

Blat=[Blat1;Blat2;Blat3;Blat4;Blat5];

Clat=diag([1,1,1,1,1]);

Dlat=zeros(5,2);

SYSlat=ss(Alat,Blat,Clat,Dlat);
figure(2)
pzmap(SYSlat)

lambda_s=Elat(5,5);
lambda_rollio=Elat(2,2);
lambda_dr=Elat(3,3);

puls_dr=sqrt(real(lambda_dr)^2+imag(lambda_dr)^2);
sm_dr=-real(lambda_dr)/puls_dr;




