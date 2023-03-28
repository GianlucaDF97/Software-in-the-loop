function err_dist = haversine(long_smooth,long_sim,lat_smooth,lat_sim )

r=6371*10^3; %raggio terra in m


err_dist = 2*r*asin(sqrt(sin((lat_smooth-lat_sim)/2)^2+cos(lat_sim)*cos(lat_smooth)*sin((long_smooth-long_sim)/2)^2 ));
