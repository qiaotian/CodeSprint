package jp.co.worksap.intern.entities.region;

import jp.co.worksap.intern.entities.ICsvMasterDTO;

public class RegionMstDTO implements ICsvMasterDTO {
	/**
	 * 
	 */
	private static final long serialVersionUID = -3711231132225687846L;
	private Long regionId;
	private String name;
	private Long managerId;

	/**
	 * Default Constructor 
	 * 
	 * @param regionId
	 * @param name
	 * @param managerId
	 */
	public RegionMstDTO(Long regionId, String name, Long managerId) {
		super();
		this.regionId = regionId;
		this.name = name;
		this.managerId = managerId;
	}

	public Long getRegionId() {
		return regionId;
	}

	public String getName() {
		return name;
	}

	public Long getManagerId() {
		return managerId;
	}

}
