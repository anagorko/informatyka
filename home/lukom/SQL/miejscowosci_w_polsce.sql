USE miejscowosci_w_polsce;

DROP TABLE IF EXISTS wojewodztwa;

CREATE TABLE wojewodztwa(
id_wojewodztwa VARCHAR(100),
nazwa_wojewodztwa VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/110/wojewodztwa.txt'
INTO TABLE wojewodztwa LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS powiaty;

CREATE TABLE powiaty(
id_powiatu VARCHAR(100),
id_wojewodztwa VARCHAR(100),
nazwa_powiatu VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/110/powiaty.txt'
INTO TABLE powiaty LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS gminy;

CREATE TABLE gminy(
id_gminy VARCHAR(100),
id_powiatu VARCHAR(100),
nazwa_gminy VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/110/gminy.txt'
INTO TABLE gminy LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS miejscowosci;

CREATE TABLE miejscowosci(
id_miejscowosci VARCHAR(100),
id_gminy VARCHAR(100),
nazwa_miejscowosci VARCHAR(100),
typ_miejscowosci VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/110/miejscowosci.txt'
INTO TABLE miejscowosci LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

#110.1
/*
SELECT COUNT(*) AS ilosc_miast
FROM miejscowosci
WHERE typ_miejscowosci = 'miasto';
*/
#110.2
/*
SELECT nazwa_powiatu, typ_miejscowosci, COUNT(*) AS ilosc
FROM miejscowosci
	JOIN gminy ON gminy.id_gminy = miejscowosci.id_gminy
	JOIN powiaty ON powiaty.id_powiatu = gminy.id_powiatu
WHERE nazwa_powiatu = 'brodnicki'
GROUP BY typ_miejscowosci
ORDER BY ilosc DESC;
*/
#110.3
/*
SELECT powiaty.nazwa_powiatu, nazwa_wojewodztwa
FROM powiaty
	JOIN wojewodztwa ON wojewodztwa.id_wojewodztwa = powiaty.id_wojewodztwa
	,(SELECT nazwa_powiatu, COUNT(*) AS ilosc
	FROM powiaty
	GROUP BY nazwa_powiatu
	HAVING ilosc > 1)x
WHERE powiaty.nazwa_powiatu = x.nazwa_powiatu
ORDER BY powiaty.nazwa_powiatu, nazwa_wojewodztwa;
*/
#110.4
/*
SELECT COUNT(x.nazwa_gminy) as ilosc
FROM
	(SELECT nazwa_gminy
	FROM miejscowosci
		JOIN gminy ON gminy.id_gminy = miejscowosci.id_gminy
		JOIN powiaty ON powiaty.id_powiatu = gminy.id_powiatu
		JOIN wojewodztwa ON wojewodztwa.id_wojewodztwa = powiaty.id_wojewodztwa
	WHERE nazwa_wojewodztwa = 'kujawsko-pomorskie'
		AND gminy.id_gminy NOT IN 
			(SELECT gminy.id_gminy
                	FROM miejscowosci
                	        JOIN gminy ON gminy.id_gminy = miejscowosci.id_gminy
                	WHERE typ_miejscowosci = 'miasto'
                	GROUP BY gminy.id_gminy)
	GROUP BY gminy.id_gminy)x;
*/
#110.5
#troche dlugo dziala ale daje dobry wynik
/*
SELECT nazwa_gminy, nazwa_powiatu, nazwa_wojewodztwa
FROM miejscowosci
	JOIN gminy ON gminy.id_gminy = miejscowosci.id_gminy
        JOIN powiaty ON powiaty.id_powiatu = gminy.id_powiatu
        JOIN wojewodztwa ON wojewodztwa.id_wojewodztwa = powiaty.id_wojewodztwa
WHERE nazwa_gminy LIKE 'J%'
	#gminy ktore maja chociaz jedno miasto pod soba
	AND gminy.id_gminy IN
		(SELECT gminy.id_gminy
                FROM miejscowosci
                	JOIN gminy ON gminy.id_gminy = miejscowosci.id_gminy
                WHERE typ_miejscowosci = 'miasto'
                GROUP BY gminy.id_gminy)
	#gminy, ktore maja tylko jedna jednostke administracyjna pod soba
	AND gminy.id_gminy IN
		(SELECT gminy.id_gminy
        	FROM miejscowosci
                	JOIN gminy ON gminy.id_gminy = miejscowosci.id_gminy
        	GROUP BY gminy.id_gminy
        	HAVING COUNT(*) = 1);
*/
