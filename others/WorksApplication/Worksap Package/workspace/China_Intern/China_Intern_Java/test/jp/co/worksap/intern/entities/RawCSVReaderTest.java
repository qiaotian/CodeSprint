package jp.co.worksap.intern.entities;

import java.io.FileReader;
import java.io.IOException;

import jp.co.worksap.intern.constants.Constants;

import org.junit.Test;

import au.com.bytecode.opencsv.CSVReader;

public class RawCSVReaderTest {
	private static final String ADDRESS_FILE = Constants.DEFAULT_CSV_FOLDER
			+ "SUPERMARKET_MST.csv";

	@Test
	public void readTourTable() throws IOException {

		@SuppressWarnings("resource")
		CSVReader reader = new CSVReader(new FileReader(ADDRESS_FILE),
				Constants.DEFAULT_CSV_SEPARATOR);
		String[] nextLine;
		boolean isTitleLine = true;
		int index = 1;
		while ((nextLine = reader.readNext()) != null) {
			if (isTitleLine) {
				System.out.println("SUPERMARKET Table Columns : ["
						+ nextLine[0] + ", " + nextLine[1] + "," + nextLine[2] + "]");
				isTitleLine = false;
			} else {
				System.out.println("SUPERMARKET Record: #" + (index++)
						+ "\nSUPERMARKET ID: [" + nextLine[0] + "]\nADDRESS: [" + nextLine[1]
						+ "]\nTEL: [" + nextLine[2] + "]\n");
			}
		}
	}
}
