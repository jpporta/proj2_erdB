typedef struct cidade {
    char nome[20];
    char vizinhos[8][20];
    int distanciaVizinhos[8];
} tCidade
// Cidades
tCidade cidades[41];

// Seatle
cidades[0].nome = "Seatle";
cidades[0].vizinhos[0] = "Portland";
cidades[0].vizinhos[1] = "Boise";
cidades[0].distanciaVizinhos[0] = 170;
cidades[0].distanciaVizinhos[1] = 500;

// Portland
cidades[1].nome = "Portland";
cidades[1].vizinhos[0] = "Seatle";
cidades[1].vizinhos[1] = "San Francisco";
cidades[1].vizinhos[2] = "Lake Tahoe";
cidades[1].vizinhos[3] = "Boise";
cidades[1].distanciaVizinhos[0] = 170;
cidades[1].distanciaVizinhos[1] = 640;
cidades[1].distanciaVizinhos[2] = 580;
cidades[1].distanciaVizinhos[3] = 420;

// Boise
cidades[2].nome = "Boise";
cidades[2].vizinhos[0] = "Seatle";
cidades[2].vizinhos[1] = "Portland";
cidades[2].vizinhos[2] = "Lake Tahoe";
cidades[2].vizinhos[3] = "Yellowstone";
cidades[2].distanciaVizinhos[0] = 500;
cidades[2].distanciaVizinhos[1] = 420;
cidades[2].distanciaVizinhos[2] = 420;
cidades[2].distanciaVizinhos[3] = 670;

// San Franscisco
cidades[3].nome = "San Francisco";
cidades[3].vizinhos[0] = "Portland";
cidades[3].vizinhos[1] = "Los Angeles";
cidades[3].vizinhos[2] = "Lake Tahoe";
cidades[3].distanciaVizinhos[0] = 640;
cidades[3].distanciaVizinhos[1] = 380;
cidades[3].distanciaVizinhos[2] = 300;

// Lake Tahoe
cidades[4].nome = "Lake Tahoe";
cidades[4].vizinhos[0] = "Portland";
cidades[4].vizinhos[1] = "San Francisco";
cidades[4].vizinhos[2] = "Palm Springs";
cidades[4].vizinhos[3] = "Salt Lake City";
cidades[4].distanciaVizinhos[0] = 580;
cidades[4].distanciaVizinhos[1] = 300;
cidades[4].distanciaVizinhos[2] = 780;
cidades[4].distanciaVizinhos[3] = 520;

// Yellowstone
cidades[5].nome = "Yellowstone";
cidades[5].vizinhos[0] = "Boise";
cidades[5].vizinhos[1] = "Denver";
cidades[5].vizinhos[2] = "Minneapolis";
cidades[5].distanciaVizinhos[0] = 670;
cidades[5].distanciaVizinhos[1] = 930;
cidades[5].distanciaVizinhos[2] = 1340;

// Salt Lake City
cidades[6].nome = "Salt Lake City";
cidades[6].vizinhos[0] = "Lake Tahoe";
cidades[6].vizinhos[1] = "Las Vegas";
cidades[6].vizinhos[2] = "Phoenix";
cidades[6].vizinhos[3] = "Denver";
cidades[6].distanciaVizinhos[0] = 520;
cidades[6].distanciaVizinhos[1] = 420;
cidades[6].distanciaVizinhos[2] = 660;
cidades[6].distanciaVizinhos[3] = 530;

// Las Vegas
cidades[7].nome = "Las Vegas";
cidades[7].vizinhos[0] = "Salt Lake City";
cidades[7].vizinhos[1] = "Los Angeles";
cidades[7].vizinhos[2] = "Palm Springs";
cidades[7].vizinhos[3] = "Grand Canyon";
cidades[7].distanciaVizinhos[0] = 420;
cidades[7].distanciaVizinhos[1] = 270;
cidades[7].distanciaVizinhos[2] = 290;
cidades[7].distanciaVizinhos[3] = 470;

// Los Angeles
cidades[8].nome = "Los Angels";
cidades[8].vizinhos[0] = "San Francisco";
cidades[8].vizinhos[1] = "San Diego";
cidades[8].vizinhos[2] = "Palm Springs";
cidades[8].vizinhos[3] = "Las Vegas";
cidades[8].distanciaVizinhos[0] = 380;
cidades[8].distanciaVizinhos[1] = 120;
cidades[8].distanciaVizinhos[2] = 160;
cidades[8].distanciaVizinhos[3] = 270;

// San Diego
cidades[9].nome = "San Diego";
cidades[9].vizinhos[0] = "Los Angeles";
cidades[9].vizinhos[1] = "Phoenix";
cidades[9].vizinhos[2] = "Palm Springs";
cidades[9].distanciaVizinhos[0] = 120;
cidades[9].distanciaVizinhos[1] = 350;
cidades[9].distanciaVizinhos[2] = 140;

// Palm Springs
cidades[10].nome = "Palm Springs";
cidades[10].vizinhos[0] = "Lake Tahoe";
cidades[10].vizinhos[1] = "Los Angeles";
cidades[10].vizinhos[2] = "San Diego";
cidades[10].vizinhos[3] = "Grand Canyon";
cidades[10].vizinhos[4] = "Las Vegas";
cidades[10].distanciaVizinhos[0] = 780;
cidades[10].distanciaVizinhos[1] = 160;
cidades[10].distanciaVizinhos[2] = 140;
cidades[10].distanciaVizinhos[3] = 440;
cidades[10].distanciaVizinhos[4] = 290;

// Phoenix
cidades[11].nome = "Phoenix";
cidades[11].vizinhos[0] = "Grand Canyon";
cidades[11].vizinhos[1] = "San Diego";
cidades[11].vizinhos[2] = "San Antonio";
cidades[11].vizinhos[3] = "Dallas";
cidades[11].vizinhos[4] = "Albuquerque";
cidades[11].vizinhos[5] = "Salt Lake City";
cidades[11].distanciaVizinhos[0] = 360;
cidades[11].distanciaVizinhos[1] = 350;
cidades[11].distanciaVizinhos[2] = 990;
cidades[11].distanciaVizinhos[3] = 1070;
cidades[11].distanciaVizinhos[4] = 350;
cidades[11].distanciaVizinhos[5] = 660;

// Grand Canyin
cidades[12].nome = "Grand Canyon";
cidades[12].vizinhos[0] = "Las Vegas";
cidades[12].vizinhos[1] = "Palm Springs";
cidades[12].vizinhos[2] = "Phoenix";
cidades[12].distanciaVizinhos[0] = 470;
cidades[12].distanciaVizinhos[1] = 440;
cidades[12].distanciaVizinhos[2] = 360;

// Albuquerque
cidades[13].nome = "Albuquerque";
cidades[13].vizinhos[0] = "Phoenix";
cidades[13].distanciaVizinhos[2] = 350;

// Denver
cidades[14].nome = "Denver";
cidades[14].vizinhos[0] = "Yellowstone";
cidades[14].vizinhos[1] = "Salt Lake City";
cidades[14].vizinhos[2] = "Vail";
cidades[14].vizinhos[3] = "Aspen";
cidades[14].vizinhos[4] = "Colorado Springs";
cidades[14].vizinhos[5] = "Omaha";
cidades[14].distanciaVizinhos[0] = 930;
cidades[14].distanciaVizinhos[1] = 530;
cidades[14].distanciaVizinhos[2] = 160;
cidades[14].distanciaVizinhos[3] = 170;
cidades[14].distanciaVizinhos[4] = 120;
cidades[14].distanciaVizinhos[5] = 540;

// Vail
cidades[15].nome = "Vail";
cidades[15].vizinhos[0] = "Denver";
cidades[15].vizinhos[1] = "Aspen";
cidades[15].distanciaVizinhos[0] = 160;
cidades[15].distanciaVizinhos[1] = 80;

// Aspen
cidades[16].nome = "Aspen";
cidades[16].vizinhos[0] = "Vail";
cidades[16].vizinhos[1] = "Colorado Springs";
cidades[16].vizinhos[2] = "Denver";
cidades[16].distanciaVizinhos[0] = 80;
cidades[16].distanciaVizinhos[1] = 180;
cidades[16].distanciaVizinhos[2] = 170;

// Colorado Springs
cidades[17].nome = "Colorado Springs";
cidades[17].vizinhos[0] = "Aspen";
cidades[17].vizinhos[1] = "Dallas";
cidades[17].vizinhos[2] = "Denver";
cidades[17].distanciaVizinhos[0] = 180;
cidades[17].distanciaVizinhos[1] = 730;
cidades[17].distanciaVizinhos[2] = 120;

// San Antonio
cidades[18].nome = "San Antonio";
cidades[18].vizinhos[0] = "Dallas";
cidades[18].vizinhos[1] = "Phoenix";
cidades[18].vizinhos[2] = "Houston";
cidades[18].distanciaVizinhos[0] = 280;
cidades[18].distanciaVizinhos[1] = 990;
cidades[18].distanciaVizinhos[2] = 310;

// Houston H20
cidades[19].nome = "Houston";
cidades[19].vizinhos[0] = "Dallas";
cidades[19].vizinhos[1] = "San Antonio";
cidades[19].vizinhos[2] = "Nova Orleans";
cidades[19].distanciaVizinhos[0] = 250;
cidades[19].distanciaVizinhos[1] = 310;
cidades[19].distanciaVizinhos[2] = 530;

// Dallas
cidades[20].nome = "Dallas";
cidades[20].vizinhos[0] = "Colorado Springs";
cidades[20].vizinhos[1] = "Phoenix";
cidades[20].vizinhos[2] = "San Antonio";
cidades[20].vizinhos[3] = "Houston";
cidades[20].vizinhos[4] = "Atlanta";
cidades[20].vizinhos[5] = "Little Rock";
cidades[20].vizinhos[6] = "Kansas City";
cidades[20].distanciaVizinhos[0] = 730;
cidades[20].distanciaVizinhos[1] = 1070;
cidades[20].distanciaVizinhos[2] = 280;
cidades[20].distanciaVizinhos[3] = 250;
cidades[20].distanciaVizinhos[4] = 790;
cidades[20].distanciaVizinhos[5] = 320;
cidades[20].distanciaVizinhos[6] = 550;

// Mineapolis
cidades[21].nome = "Mineapolis";
cidades[21].vizinhos[0] = "Yellowstone";
cidades[21].vizinhos[1] = "Omaha";
cidades[21].vizinhos[2] = "Chicago";
cidades[21].vizinhos[3] = "Milwaukee";
cidades[21].distanciaVizinhos[0] = 1340;
cidades[21].distanciaVizinhos[1] = 380;
cidades[21].distanciaVizinhos[2] = 410;
cidades[21].distanciaVizinhos[3] = 340;

// Omaha
cidades[22].nome = "Omaha";
cidades[22].vizinhos[0] = "Mineapolis";
cidades[22].vizinhos[1] = "Denver";
cidades[22].vizinhos[2] = "Kansas City";
cidades[22].vizinhos[3] = "Chicago";
cidades[22].distanciaVizinhos[0] = 380;
cidades[22].distanciaVizinhos[1] = 540;
cidades[22].distanciaVizinhos[2] = 190;
cidades[22].distanciaVizinhos[3] = 470;

// Milwaukee
cidades[23].nome = "Milwaukee";
cidades[23].vizinhos[0] = "Mineapolis";
cidades[23].vizinhos[1] = "Chicago";
cidades[23].distanciaVizinhos[0] = 340;
cidades[23].distanciaVizinhos[1] = 90;

// Chicago
cidades[24].nome = "Chicago";
cidades[24].vizinhos[0] = "Milwaukee";
cidades[24].vizinhos[1] = "Mineapolis";
cidades[24].vizinhos[2] = "Omaha";
cidades[24].vizinhos[3] = "St Louis";
cidades[24].vizinhos[4] = "Indianopolis";
cidades[24].vizinhos[5] = "Washington";
cidades[24].vizinhos[6] = "Detroid";
cidades[24].distanciaVizinhos[0] = 90;
cidades[24].distanciaVizinhos[1] = 410;
cidades[24].distanciaVizinhos[2] = 470;
cidades[24].distanciaVizinhos[3] = 300;
cidades[24].distanciaVizinhos[4] = 180;
cidades[24].distanciaVizinhos[5] = 700;
cidades[24].distanciaVizinhos[6] = 280;