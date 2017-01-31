USE portal

DROP TABLE IF EXISTS uzytkownicy;
CREATE TABLE uzytkownicy
(
	id_uzytkownika INT,
	imie VARCHAR(100),
	nazwisko VARCHAR(100),
	kraj VARCHAR(100),
	plec VARCHAR(1)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/102/uzytkownicy.txt' INTO TABLE uzytkownicy LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS znajomosci;
CREATE TABLE znajomosci
(
	znajomy1 INT,
	znajomy2 INT,
	data DATE
);