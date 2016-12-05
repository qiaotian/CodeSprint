package jp.co.worksap.intern.entities.product;

import jp.co.worksap.intern.constants.PriceUnitType;
import jp.co.worksap.intern.entities.ICsvMasterDTO;

public class ProductMstDto implements ICsvMasterDTO {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1950118052473203296L;
	private Long productMstId;
	private String productType;
	private String productName;
	private double price;
	private PriceUnitType priceUnit;

	/**
	 * Default Constructor
	 * 
	 * @param productMstId
	 * @param productType
	 * @param productName
	 * @param price
	 * @param priceUnit
	 */
	public ProductMstDto(Long productMstId, String productType, String productName, double price, PriceUnitType priceUnit) {
		super();
		this.productMstId = productMstId;
		this.productType = productType;
		this.productName = productName;
		this.price = price;
		this.priceUnit = priceUnit;
	}

	public Long getProductMstId() {
		return productMstId;
	}

	public String getProductType() {
		return productType;
	}

	public String getProductName() {
		return productName;
	}

	public double getPrice() {
		return price;
	}

	public PriceUnitType getPriceUnit() {
		return priceUnit;
	}

	

}