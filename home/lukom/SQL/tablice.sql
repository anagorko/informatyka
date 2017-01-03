USE tablice;

DROP TABLE IF EXISTS tablice;

CREATE TABLE tablice(
ozn VARCHAR(100),
powiat VARCHAR(100),
siedziba VARCHAR(100),
rodzaj VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../matura/tablice.txt'
INTO TABLE tablice IGNORE 1 LINES;


DROP TABLE IF EXISTS uslugi;

CREATE TABLE uslugi(
nip VARCHAR(100),
onz VARCHAR(100),
nr VARCHAR(100),
rodzaj VARCHAR(100),
rata INT
);

LOAD DATA LOCAL INFILE '../../../matura/uslugi.txt'
INTO TABLE uslugi IGNORE 1 LINES;

DROP TABLE IF EXISTS nip_firm;

CREATE TABLE nip_firm(
nip VARCHAR(100),
firma VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../matura/nip_firm.txt'
INTO TABLE nip_firm IGNORE 1 LINES;





#QUERIES

#a)

SELECT SUM(rata) AS leasing
FROM uslugi
WHERE rodzaj='L';
SELECT SUM(rata) AS wynajem
FROM uslugi
WHERE rodzaj='W';

#b)

SELECT onz, nr
FROM uslugi, nip_firm
WHERE nip_firm.nip = uslugi.nip
	AND nip_firm.firma = 'BARTEX'
ORDER BY nr;

#c)

#d)

