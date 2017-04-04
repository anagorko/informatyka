DROP TABLE IF EXISTS data;
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

