USE bezpieczenstwo_w_szkole;

DROP TABLE IF EXISTS ankiety;

CREATE TABLE ankiety(
nr_ankiety VARCHAR(100),
pyt1 INT,
pyt2 INT,
pyt3 INT,
pyt4 INT,
pyt5 INT,
pyt6 INT,
id_szkoly VARCHAR(100),
plec VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/99/ankiety.txt'
INTO TABLE ankiety IGNORE 1 LINES;

DROP TABLE IF EXISTS szkoly;

CREATE TABLE szkoly(
id_szkoly VARCHAR(100),
rodzaj_szkoly VARCHAR(100),
kod_gminy VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/99/szkoly.txt'
INTO TABLE szkoly IGNORE 1 LINES;

DROP TABLE IF EXISTS gminy;

CREATE TABLE gminy(
kod_gminy VARCHAR(100),
nazwa_gminy VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/99/gminy.txt'
INTO TABLE gminy IGNORE 1 LINES;

#99.1
/*
SELECT plec, COUNT(plec)
FROM ankiety
GROUP BY TRIM(plec)\G
#tutaj plec 'k' liczy dwa razy. Dlaczego?
*/
#99.2
/*
SELECT rodzaj_szkoly, ROUND(AVG(ankiety.pyt1),2) AS 'pyt 1', ROUND(AVG(ankiety.pyt2),2) AS 'pyt 2', 
ROUND(AVG(ankiety.pyt3),2) AS 'pyt 3', ROUND(AVG(ankiety.pyt4),2) AS 'pyt 4',
ROUND(AVG(ankiety.pyt5),2) AS 'pyt 5', ROUND(AVG(ankiety.pyt6),2) AS 'pyt 6'
FROM ankiety JOIN szkoly ON ankiety.id_szkoly = szkoly.id_szkoly
GROUP BY rodzaj_szkoly;
*/
#99.3

SELECT kod_gminy, ROUND(AVG(pyt6),2) AS 'średnia odpowiedzi'
FROM ankiety
	JOIN szkoly ON szkoly.id_szkoly = ankiety.id_szkoly
GROUP BY kod_gminy
ORDER BY 'średnia odpowiedzi' DESC\G
#NIE WIEM CZEMU WYSWIETLA WYNIKI NIE W KOLEJNOSCI

#99.4
/*
SELECT rodzaj_szkoly, COUNT(pyt3) AS ilosc
FROM ankiety
	JOIN szkoly ON ankiety.id_szkoly = szkoly.id_szkoly
WHERE pyt3 = 5
GROUP BY rodzaj_szkoly
ORDER BY rodzaj_szkoly
*/
#99.5
/*
SELECT nazwa_gminy, COUNT(nr_ankiety) AS 'ilosc uczniow'
FROM ankiety
	JOIN szkoly ON ankiety.id_szkoly = szkoly.id_szkoly
	JOIN gminy ON szkoly.kod_gminy = szkoly.kod_gminy
GROUP BY nazwa_gminy
ORDER BY 'ilosc uczniow' DESC LIMIT 1\G
*/
#99.6
/*
SELECT rodzaj_szkoly, plec, COUNT(nr_ankiety) AS ilosc
FROM ankiety
	JOIN szkoly ON szkoly.id_szkoly = ankiety.id_szkoly
WHERE pyt1 = 5
GROUP BY rodzaj_szkoly, plec;
*/
