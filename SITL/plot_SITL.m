lat=logsout.get("Lat_deg").Values;
long=logsout.get("Lon_deg").Values;
lat=reshape(lat.Data,[1,length(lat.Time)]);
long=reshape(long.Data,[1,length(long.Time)]);

waypoint=[
0 0 23 0 41.87917361622426, 12.703963012862376 40
0 0 22 0 41.879031221935236, 12.704553275157421 50
0 0 20 0 41.87913162110912, 12.705711077711106 60
0 0 20 0 41.87974786085141, 12.706106311532222 70
0 0 24 0 41.880620279983006, 12.706190008104187 80
0 0 25 0 41.88139921557965, 12.705194948878743 50
0 0 25 0 41.881655396766476, 12.7038837026001 70
];
coordinate=waypoint(:,5:6);
posizione_iniziale=[41.87974753565198, 12.703602634460767];

geoplot(lat,long,"c","LineWidth",3)
hold on
geoplot(posizione_iniziale(1),posizione_iniziale(2),"ro",'Linewidth',1.5,"MarkerSize",8,"MarkerFaceColor","b")
hold on
for i=1:length(coordinate)
geoplot(coordinate(i,1),coordinate(i,2),"Vg",'Linewidth',1.5,"MarkerSize",10,"MarkerFaceColor","k")
end
geobasemap satellite