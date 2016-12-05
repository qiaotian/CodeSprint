package jp.co.worksap.intern.entities.supermarket;

import jp.co.worksap.intern.entities.ICsvMasterDTO;

public class SupermarketMstDTO implements ICsvMasterDTO {
	/**
	 * 
	 */
	private static final long serialVersionUID = -3711231132225687846L;
	private Long supermarketId;
	private String address;
	private String tel;

	/**
	 * Default Constructor 
	 * 
	 * @param supermarketId
	 * @param supermarketName
	 * @param address
	 * @param tel
	 */
	public SupermarketMstDTO(Long supermarketId, String address,
			String tel) {
		super();
		this.supermarketId = supermarketId;
		this.address = address;
		this.tel = tel;
	}

	public Long getSupermarketId() {
		return supermarketId;
	}

	public String getAddress() {
		return address;
	}

	public String getTel() {
		return tel;
	}

}
