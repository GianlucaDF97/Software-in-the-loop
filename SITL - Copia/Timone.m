function [CYdR,CldR,CndR,KCYdR,KCldR,KCndR]=Timone(OGb,A,B,K)
%Fuzione che calcola le derivate di controllo rispetto all'angolo del
%timone; la posizione del baricentro viene data dall'esterno rispetto al
%polo utilizzato nelle simulazioni aerodinamiche

dRvec=2:2:6;

%Importo i risultati ottenuti


cd TIMONE

FxdR=zeros(1,3);
FydR=zeros(1,3);
FzdR=zeros(1,3);
MxdR=zeros(1,3);
MydR=zeros(1,3);
MzdR=zeros(1,3);

clear j

j=1;
for dR=2:2:6

    dR_1=num2str(dR);
    cartelladR=strcat('dR=',dR_1);
    cd(cartelladR)
    
    
    load minfo1_e1.csv
    load minfo1_e2.csv
    load minfo1_e3.csv
    load minfo1_e4.csv
    load minfo1_e5.csv
    load minfo1_e6.csv
    FxdR(j)=minfo1_e1(end,3);
    FydR(j)=minfo1_e2(end,3);
    FzdR(j)=minfo1_e3(end,3);
    MxdR(j)=minfo1_e4(end,3);
    MydR(j)=minfo1_e5(end,3);
    MzdR(j)=minfo1_e6(end,3);
    clear minfo1_e1
    clear minfo1_e2
    clear minfo1_e3
    clear minfo1_e4
    clear minfo1_e5
    clear minfo1_e6
    cd ..
    j=j+1;
    
end

cd ..

FxbdR=zeros(1,3);
FybdR=zeros(1,3);
FzbdR=zeros(1,3);
MxbdR=zeros(1,3);
MybdR=zeros(1,3);
MzbdR=zeros(1,3);

clear i
% Sposto nel baricentro forze e momenti di controllo
for i=1:3
    
    %forze
    RwdR=[FxdR(i) FydR(i) FzdR(i)]';
    RbdR=RwdR;
    FxbdR(i)=RbdR(1);
    FybdR(i)=RbdR(2);
    FzbdR(i)=RbdR(3);
    
    %momenti
    MowdR=[MxdR(i) MydR(i) MzdR(i)]'; 
    MgdR=MowdR+cross(OGb,RbdR);
    MxbdR(i)=MgdR(1);
    MybdR(i)=MgdR(2);
    MzbdR(i)=MgdR(3);
    
    clear RwdR RbdR MowdR MgdR     
end

% calcolo dei coefficienti con formula linearizzata
% Adimensionalizzazione
CFybdR=FybdR./A;
CMxbdR=MxbdR./B;
CMzbdR=MzbdR./B;
% Interpolazione (1/deg)
KCYdR=polyfit(dRvec,CFybdR,1);
KCldR=polyfit(dRvec,CMxbdR,1);
KCndR=polyfit(dRvec,CMzbdR,1);
% conversione in 1/rad
CYdR=-KCYdR(1)*180/pi;
CldR=KCldR(1)*180/pi;
CndR=KCndR(1)*180/pi;


end