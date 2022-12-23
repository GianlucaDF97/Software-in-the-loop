function H = jac_H_F1B(prediction,EULERO,rx,ry,rz,g)
%% inizializzazione vettore
lat = prediction(1); long = prediction(2); h = prediction(3);

vn = prediction(4); ve = prediction(5);

an = prediction(7); ae = prediction(8); ad = prediction(9);

p = prediction(10); q = prediction(11) ;r = prediction(12);

baccx = prediction(13); baccy = prediction(14); baccz = prediction(15);

bp = prediction(16); bq = prediction(17); br = prediction(18); 

phi = EULERO(1); theta = EULERO(2); psi = EULERO(3);
%% Jacobiano
H=[  1, 0, 0, 0, 0, 0,                                                0,                                                0,                   0,                                                                                                               0,                                                                              0,                                                                                0, 0, 0, 0, 0, 0, 0;
 0, 1, 0, 0, 0, 0,                                                0,                                                0,                   0,                                                                                                               0,                                                                              0,                                                                                0, 0, 0, 0, 0, 0, 0;
 0, 0, 1, 0, 0, 0,                                                0,                                                0,                   0,                                                                                                               0,                                                                              0,                                                                                0, 0, 0, 0, 0, 0, 0;
 0, 0, 0, 1, 0, 0,                                                0,                                                0,                   0,   ry*(sin(phi)*sin(psi) + cos(phi)*cos(psi)*sin(theta)) + rz*(cos(phi)*sin(psi) - cos(psi)*sin(phi)*sin(theta)), rz*cos(psi)*cos(theta) - rx*(sin(phi)*sin(psi) + cos(phi)*cos(psi)*sin(theta)), - rx*(cos(phi)*sin(psi) - cos(psi)*sin(phi)*sin(theta)) - ry*cos(psi)*cos(theta), 0, 0, 0, 0, 0, 0;
 0, 0, 0, 0, 1, 0,                                                0,                                                0,                   0, - ry*(cos(psi)*sin(phi) - cos(phi)*sin(psi)*sin(theta)) - rz*(cos(phi)*sin(psi) + sin(phi)*sin(psi)*sin(theta)), rx*(cos(psi)*sin(phi) - cos(phi)*sin(psi)*sin(theta)) + rz*cos(theta)*sin(psi),   rx*(cos(phi)*sin(psi) + sin(phi)*sin(psi)*sin(theta)) - ry*cos(theta)*sin(psi), 0, 0, 0, 0, 0, 0;
 0, 0, 0, 0, 0, 0,                              cos(psi)*cos(theta),                              cos(theta)*sin(psi),         -sin(theta),                                                                                                     q*ry + r*rz,                                                                  p*ry - 2*q*rx,                                                                    p*rz - 2*r*rx, 1, 0, 0, 0, 0, 0;
 0, 0, 0, 0, 0, 0, cos(psi)*sin(phi)*sin(theta) - cos(phi)*sin(psi), cos(phi)*cos(psi) + sin(phi)*sin(psi)*sin(theta), cos(theta)*sin(phi),                                                                                                   q*rx - 2*p*ry,                                                                    p*rx + r*rz,                                                                    q*rz - 2*r*ry, 0, 1, 0, 0, 0, 0;
 0, 0, 0, 0, 0, 0, sin(phi)*sin(psi) + cos(phi)*cos(psi)*sin(theta), cos(phi)*sin(psi)*sin(theta) - cos(psi)*sin(phi), cos(phi)*cos(theta),                                                                                                   r*rx - 2*p*rz,                                                                  r*ry - 2*q*rz,                                                                      p*rx + q*ry, 0, 0, 1, 0, 0, 0;
 0, 0, 0, 0, 0, 0,                                                0,                                                0,                   0,                                                                                                               1,                                                                              0,                                                                                0, 0, 0, 0, 1, 0, 0;
 0, 0, 0, 0, 0, 0,                                                0,                                                0,                   0,                                                                                                               0,                                                                              1,                                                                                0, 0, 0, 0, 0, 1, 0;
 0, 0, 0, 0, 0, 0,                                                0,                                                0,                   0,                                                                                                               0,                                                                              0,                                                                                1, 0, 0, 0, 0, 0, 1];

end

