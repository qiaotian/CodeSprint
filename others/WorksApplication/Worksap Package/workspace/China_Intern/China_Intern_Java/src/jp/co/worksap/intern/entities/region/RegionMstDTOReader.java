package jp.co.worksap.intern.entities.region;

import java.io.IOException;

import jp.co.worksap.intern.constants.Constants;
import jp.co.worksap.intern.entities.AbstractDTOReader;

public class RegionMstDTOReader extends AbstractDTOReader<RegionMstDTO> {
	private static final int COLUMN_INDEX_REGION_ID = 0;
	private static final int COLUMN_INDEX_NAME = 1;
	private static final int COLUMN_INDEX_MANAGER_ID = 2;

	private String fileAddress = Constants.DEFAULT_CSV_FOLDER
			+ "REGION_MST.csv";

	/**
	 * use default file address
	 * 
	 * @throws IOException
	 */
	public RegionMstDTOReader() throws IOException {
		super(RegionMstDTOReader.class.getName());
		super.init();
	}

	/**
	 * use customize file address
	 * 
	 * @param fileAddress
	 * @throws IOException
	 */
	public RegionMstDTOReader(final String fileAddress) throws IOException {
		super(RegionMstDTOReader.class.getName());
		this.fileAddress = fileAddress;
		super.init();
	}

	@Override
	protected String getFileArress() {
		return fileAddress;
	}

	@Override
	protected RegionMstDTO convertArrayToDTO(String[] value) throws IOException {
		Long regionId = Long.valueOf(value[COLUMN_INDEX_REGION_ID]);
		String name = value[COLUMN_INDEX_NAME];
		Long managerId = Long.valueOf(value[COLUMN_INDEX_MANAGER_ID]);

		RegionMstDTO dto = new RegionMstDTO(regionId, name, managerId);
		return dto;
	}
}
