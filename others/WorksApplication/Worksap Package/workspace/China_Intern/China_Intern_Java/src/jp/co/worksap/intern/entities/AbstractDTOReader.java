package jp.co.worksap.intern.entities;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import jp.co.worksap.intern.constants.Constants;
import jp.co.worksap.intern.constants.Messages;
import jp.co.worksap.intern.util.Utilities;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import au.com.bytecode.opencsv.CSVReader;

public abstract class AbstractDTOReader<E extends ICsvMasterDTO> {

	private List<E> values = null;
	protected Log log = null;

	protected AbstractDTOReader(String className) {
		log = LogFactory.getLog(className);
	}

	protected abstract E convertArrayToDTO(String[] value) throws IOException;

	/**
	 * file path of csv file
	 */
	protected abstract String getFileArress();

	public List<E> getValues() {
		return values;
	}

	protected void init() throws IOException {
		FileReader fileReader = null;
		try {
			fileReader = new FileReader(getFileArress());
			values = new ArrayList<E>();
			if (fileReader != null && fileReader.ready()) {
				CSVReader csvReader = new CSVReader(fileReader,
						Constants.DEFAULT_CSV_SEPARATOR);
				try {
					csvReader.readNext();
					// String[] titleLine = csvReader.readNext();
					String[] value = null;
					while ((value = csvReader.readNext()) != null) {
						if (value.length == 0){
							continue;
						}
						String[] newFields = new String[value.length];
						int i =0;
						for (String field : value){
							newFields[i++] = field.replace("\\n", "");
						}
						values.add(convertArrayToDTO(newFields));
					}
				} catch (IOException e) {
					log.error(Messages.ERROR_READ_CSV, e);
				} finally {
					Utilities.closeSilently(csvReader);
				}
			}
		} catch (FileNotFoundException e) {
			log.error(Messages.ERROR_CSV_NOT_FOUND, e);
		} finally {
			Utilities.closeSilently(fileReader);
		}
	}

}
