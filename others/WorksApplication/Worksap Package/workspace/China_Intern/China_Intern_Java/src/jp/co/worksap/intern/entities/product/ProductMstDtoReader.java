package jp.co.worksap.intern.entities.product;

import java.io.IOException;

import jp.co.worksap.intern.constants.Constants;
import jp.co.worksap.intern.constants.PriceUnitType;
import jp.co.worksap.intern.entities.AbstractDTOReader;

public class ProductMstDtoReader extends AbstractDTOReader<ProductMstDto> {
	private static final int COLUMN_INDEX_PRODUCT_ID = 0;
	private static final int COLUMN_INDEX_PRODUCT_TYPE = 1;
	private static final int COLUMN_INDEX_PRODUCT_NAME = 2;
	private static final int COLUMN_INDEX_PRICE = 3;
	private static final int COLUMN_INDEX_PRICE_UNIT = 4;

	private String fileAddress = Constants.DEFAULT_CSV_FOLDER
			+ "PRODUCT_MST.csv";

	/**
	 * use default file address
	 * 
	 * @throws IOException
	 */
	public ProductMstDtoReader() throws IOException {
		super(ProductMstDtoReader.class.getName());
		super.init();
	}

	/**
	 * use customize file address
	 * 
	 * @param fileAddress
	 * @throws IOException
	 */
	public ProductMstDtoReader(final String fileAddress) throws IOException {
		super(ProductMstDtoReader.class.getName());
		this.fileAddress = fileAddress;
		super.init();
	}

	@Override
	protected String getFileArress() {
		return fileAddress;
	}

	@Override
	protected ProductMstDto convertArrayToDTO(String[] value) throws IOException {

		Long productMstId = Long.valueOf(value[COLUMN_INDEX_PRODUCT_ID]);
		String productType = value[COLUMN_INDEX_PRODUCT_TYPE];
		String productName = value[COLUMN_INDEX_PRODUCT_NAME];
		double price = Double.parseDouble(value[COLUMN_INDEX_PRICE]);
		PriceUnitType priceUnit = PriceUnitType.valueOfString(value[COLUMN_INDEX_PRICE_UNIT]);

		ProductMstDto dto = new ProductMstDto(productMstId, productType, productName, price, priceUnit);
		return dto;
	}
}
