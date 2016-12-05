package jp.co.worksap.intern.entities.staff;

import java.io.IOException;

import jp.co.worksap.intern.constants.Constants;
import jp.co.worksap.intern.entities.AbstractDTOReader;

public class StaffDTOReader extends AbstractDTOReader<StaffDTO> {
	private static final int COLUMN_INDEX_STAFF_ID = 0;
	private static final int COLUMN_INDEX_NAME = 1;
	private static final int COLUMN_INDEX_GENDER = 2;
	private static final int COLUMN_INDEX_RANK = 3;
	private static final int COLUMN_INDEX_POSITION = 4;
	private static final int COLUMN_INDEX_SUPERMARKET_ID = 5;
	

	private String fileAddress = Constants.DEFAULT_CSV_FOLDER+"STAFF_MST.csv";

	/**
	 * use default file address
	 * 
	 * @throws IOException
	 */
	public StaffDTOReader() throws IOException {
		super(StaffDTOReader.class.getName());
		super.init();
	}

	/**
	 * use customize file address
	 * 
	 * @param fileAddress
	 * @throws IOException
	 */
	public StaffDTOReader(final String fileAddress) throws IOException {
		super(StaffDTOReader.class.getName());
		this.fileAddress = fileAddress;
		super.init();
	}

	@Override
	protected String getFileArress() {
		return fileAddress;
	}

	@Override
	protected StaffDTO convertArrayToDTO(String[] value) throws IOException {

		Long staffId = Long.valueOf(value[COLUMN_INDEX_STAFF_ID]);
		String name = value[COLUMN_INDEX_NAME];
		String gender = value[COLUMN_INDEX_GENDER];
		Long supermarketId = Long.valueOf(value[COLUMN_INDEX_SUPERMARKET_ID]);
		RankType rank = RankType.valueOfString(value[COLUMN_INDEX_RANK]);
		PositionType position = PositionType.valueOfString(value[COLUMN_INDEX_POSITION]);
		
		StaffDTO dto = new StaffDTO(staffId, name, gender, rank, position, supermarketId);
		return dto;
	}
}
