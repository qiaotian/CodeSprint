package jp.co.worksap.intern.entities.customer;

import jp.co.worksap.intern.entities.ICsvMasterDTO;

public class CustomerDTO implements ICsvMasterDTO {
	/**
	 * 
	 */
	private static final long serialVersionUID = -5538243149394207296L;

	private Long customerId;
	private String name;
	private String gender;
	private String tel;

	/**
	 * Default Constructor
	 * 
	 * @param customerId
	 * @param name
	 * @param gender
	 * @param birthday
	 * @param nationality
	 * @param passportNo
	 * @param address
	 * @param email
	 * @param tel
	 */
	public CustomerDTO(Long customerId, String name, String gender, String tel) {
		super();
		this.customerId = customerId;
		this.name = name;
		this.gender = gender;
		this.tel = tel;
	}

	public Long getCustomerId() {
		return customerId;
	}

	public String getName() {
		return name;
	}

	public String getGender() {
		return gender;
	}

	public String getTel() {
		return tel;
	}

}
