DROP TABLE IF EXISTS data;

PRAGMA main.page_size = 4096;
PRAGMA main.cache_size=10000;
PRAGMA main.locking_mode=EXCLUSIVE;
PRAGMA main.synchronous=NORMAL;
PRAGMA main.journal_mode=WAL;
PRAGMA main.cache_size=5000;

CREATE TABLE data
(
	id_serial char,
	id_measurement int,
	timestamp int,
	temperature INT,
	pressure INT,
	spectrogram BLOB,
	tag char[100]
);

CREATE INDEX timestamp ON data (timestamp);

