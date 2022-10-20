 function Y = measure_F1B(stato,EULERO,rx,ry,rz,g)
%% Inizializzazione vettore


Y=zeros(11,1);

 
lat = stato(1); long = stato(2); h = stato(3);

vn = stato(4); ve = stato(5); 

an = stato(7); ae = stato(8); ad = stato(9);

p = stato(10); q = stato(11) ;r = stato(12);

 baccx = stato(13); baccy = stato(14); baccz = stato(15);

% baccx = 0.0392; baccy = -0.0598; baccz = 0.0384;
% 
% bp = 8.6998e-05; bq = 0.0017; br = 0.0031; 
bp = stato(16); bq = stato(17); br =stato(18); 

phi = EULERO(1); theta = EULERO(2); psi = EULERO(3);

%% Equazioni di misura

Y(1)=lat;
Y(2)=long;
Y(3)=h;
 
Y(4)= vn + (sin(phi)*sin(psi) + cos(phi)*cos(psi)*sin(theta))*(p*ry - q*rx) + (cos(phi)*sin(psi) - cos(psi)*sin(phi)*sin(theta))*(p*rz - r*rx) + cos(psi)*cos(theta)*(q*rz - r*ry);
             
Y(5)= ve - (cos(psi)*sin(phi) - cos(phi)*sin(psi)*sin(theta))*(p*ry - q*rx) - (cos(phi)*sin(psi) + sin(phi)*sin(psi)*sin(theta))*(p*rz - r*rx) + cos(theta)*sin(psi)*(q*rz - r*ry);
  
  
% Y(6)=phi;
% Y(7)=theta;
% Y(8)=psi;
                                                                                                                                                                            
                                                                                                                                                                                 


Y(6)=  baccx   +  an*cos(theta)*cos(psi) + ae*cos(theta)*sin(psi) - sin(theta)*(ad - g) + q*(p*ry - q*rx) + r*(p*rz - r*rx);
  
Y(7)=  baccy +an*(cos(psi)*sin(phi)*sin(theta) - cos(phi)*sin(psi)) + ae*(cos(phi)*cos(psi) + sin(phi)*sin(psi)*sin(theta))+ cos(theta)*sin(phi)*(ad - g) - p*(p*ry - q*rx) + r*(q*rz - r*ry);
    
Y(8) =baccz +an*(sin(phi)*sin(psi) + cos(phi)*cos(psi)*sin(theta)) + ae*(cos(phi)*sin(psi)*sin(theta) - cos(psi)*sin(phi))+ cos(phi)*cos(theta)*(ad - g)  - p*(p*rz - r*rx) - q*(q*rz - r*ry) ;   
    
Y(9) = bp + p;               	
Y(10) = bq + q;
Y(11) = br  + r;
end

