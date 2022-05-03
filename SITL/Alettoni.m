function [CYdA,CldA,CndA,KCYdA,KCldA,KCndA]=Alettoni(OGb,A,B,K)
%Funzione che calcola i Coefficienti di forza e momenti laterali dericati
%rispetto all'angolo di alettoni; lo spostamento nel baricentro avviene
%assegnando dall'esterno la posizione del baricentro rispetto al polo
%utilizzato nella simulazione aerodinamica

dAvec=2:2:8;

%Importo i risultati ottenuti


cd ALETTONI

FxdA=zeros(1,4);
FydA=zeros(1,4);
FzdA=zeros(1,4);
MxdA=zeros(1,4);
MydA=zeros(1,4);
MzdA=zeros(1,4);

clear j

j=1;
for dA=2:2:8

    dA_1=num2str(dA);
    cartelladA=strcat('dA=',dA_1);
    cd(cartelladA)
    
    
    load minfo1_e1.csv
    load minfo1_e2.csv
    load minfo1_e3.csv
    load minfo1_e4.csv
    load minfo1_e5.csv
    load minfo1_e6.csv
    FxdA(j)=minfo1_e1(end,3);
    FydA(j)=minfo1_e2(end,3);
    FzdA(j)=minfo1_e3(end,3);
    MxdA(j)=minfo1_e4(end,3);
    MydA(j)=minfo1_e5(end,3);
    MzdA(j)=minfo1_e6(end,3);
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

FxbdA=zeros(1,4);
FybdA=zeros(1,4);
FzbdA=zeros(1,4);
MxbdA=zeros(1,4);
MybdA=zeros(1,4);
MzbdA=zeros(1,4);


% Sposto nel baricentro forze e momenti di controllo
for i=1:4
    
    %forze
    RwdA=[FxdA(i) FydA(i) FzdA(i)]';
    RbdA=RwdA;
    FxbdA(i)=RbdA(1);
    FybdA(i)=RbdA(2);
    FzbdA(i)=RbdA(3);
    
    %momenti
    MowdA=[MxdA(i) MydA(i) MzdA(i)]'; 
    MgdA=MowdA+cross(OGb,RbdA);
    MxbdA(i)=MgdA(1);
    MybdA(i)=MgdA(2);
    MzbdA(i)=MgdA(3);
    
    clear RwdA RbdA MowdA MgdA     
end

% calcolo dei coefficienti con formula linearizzata
% Adimensionalizzazione
CFybdA=FybdA./A;
CMxbdA=MxbdA./B;
CMzbdA=MzbdA./B;
% Interpolazione (1/deg)
KCYdA=polyfit(dAvec,CFybdA,1);
KCldA=polyfit(dAvec,CMxbdA,1);
KCndA=polyfit(dAvec,CMzbdA,1);
% conversione in 1/rad
CYdA=KCYdA(1)*180/pi;
CldA=KCldA(1)*180/pi;
CndA=KCndA(1)*180/pi;



end