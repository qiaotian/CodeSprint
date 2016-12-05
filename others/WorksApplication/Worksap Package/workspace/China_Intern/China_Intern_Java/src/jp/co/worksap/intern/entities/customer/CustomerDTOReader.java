package jp.co.worksap.intern.entities.customer;

import java.io.IOException;

import jp.co.worksap.intern.constants.Constants;
import jp.co.worksap.intern.entities.AbstractDTOReader;

public class CustomerDTOReader extends AbstractDTOReader<CustomerDTO> {
	private static final int COLUMN_INDEX_CUSTOMER_ID = 0;
	private static final int COLUMN_INDEX_NAME = 1;
	private static final int COLUMN_INDEX_GENDER = 2;
	private static final int COLUMN_INDEX_TEL = 3;

	private String fileAddress = Constants.DEFAULT_CSV_FOLDER
			+ "CUSTOMER_MST.csv";

	/**
	 * use default file address
	 * 
	 * @throws IOException
	 */
	public CustomerDTOReader() throws IOException {
		super(CustomerDTOReader.class.getName());
		super.init();
	}

	/**
	 * use customize file address
	 * 
	 * @param fileAddress
	 * @throws IOException
	 */
	public CustomerDTOReader(final String fileAddress) throws IOException {
		super(CustomerDTOReader.class.getName());
		this.fileAddress = fileAddress;
		super.init();
	}

	@Override
	protected String getFileArress() {
		return fileAddress;
	}

	@Override
	protected CustomerDTO convertArrayToDTO(String[] value) throws IOException {

		Long customerId = Long.valueOf(value[COLUMN_INDEX_CUSTOMER_ID]);
		String name = value[COLUMN_INDEX_NAME];
		String gender = value[COLUMN_INDEX_GENDER];
		String tel = value[COLUMN_INDEX_TEL];

		CustomerDTO dto = new CustomerDTO(customerId, name, gender, tel);
		return dto;
	}
}
