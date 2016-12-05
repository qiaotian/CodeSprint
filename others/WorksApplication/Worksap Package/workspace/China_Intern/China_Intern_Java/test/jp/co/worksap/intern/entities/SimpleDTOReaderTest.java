package jp.co.worksap.intern.entities;

import static org.junit.Assert.assertNotNull;

import java.io.IOException;
import java.util.List;

import jp.co.worksap.intern.constants.Constants;
import jp.co.worksap.intern.entities.customer.CustomerDTO;
import jp.co.worksap.intern.entities.customer.CustomerDTOReader;
import jp.co.worksap.intern.entities.product.ProductMstDto;
import jp.co.worksap.intern.entities.product.ProductMstDtoReader;
import jp.co.worksap.intern.entities.region.RegionMstDTO;
import jp.co.worksap.intern.entities.region.RegionMstDTOReader;
import jp.co.worksap.intern.entities.staff.StaffDTO;
import jp.co.worksap.intern.entities.staff.StaffDTOReader;
import jp.co.worksap.intern.entities.supermarket.SupermarketMstDTO;
import jp.co.worksap.intern.entities.supermarket.SupermarketMstDTOReader;

import org.junit.Test;

public class SimpleDTOReaderTest {

	@Test
	public void readCustomerTable() throws IOException {
		CustomerDTOReader reader = new CustomerDTOReader();
		List<CustomerDTO> values = reader.getValues();
		assertNotNull(values);
		for (CustomerDTO value : values) {
			assertNotNull(value);
			assertNotNull(value.getCustomerId());
			assertNotNull(value.getGender());
			assertNotNull(value.getName());
			assertNotNull(value.getTel());
		}
	}

	@Test
	public void readEmployeeTable() throws IOException {
		StaffDTOReader reader = new StaffDTOReader();
		List<StaffDTO> values = reader.getValues();
		assertNotNull(values);
		for (StaffDTO value : values) {
			assertNotNull(value);
			assertNotNull(value.getStaffId());
			assertNotNull(value.getGender());
			assertNotNull(value.getName());
			assertNotNull(value.getPosition());
			assertNotNull(value.getRank());
			assertNotNull(value.getSupermarketId());
		}
	}

	@Test
	public void readSupermarketMstTable() throws IOException {
		SupermarketMstDTOReader reader = new SupermarketMstDTOReader();
		List<SupermarketMstDTO> values = reader.getValues();
		assertNotNull(values);
		for (SupermarketMstDTO value : values) {
			assertNotNull(value);
			assertNotNull(value.getAddress());
			assertNotNull(value.getSupermarketId());
			assertNotNull(value.getTel());
		}
	}

	@Test
	public void readRegionTable() throws IOException {
		RegionMstDTOReader reader = new RegionMstDTOReader();
		List<RegionMstDTO> values = reader.getValues();
		assertNotNull(values);
		for (RegionMstDTO value : values) {
			assertNotNull(value);
			assertNotNull(value.getManagerId());
			assertNotNull(value.getName());
			assertNotNull(value.getRegionId());
		}
	}
	
	@Test
	public void readProductTable() throws IOException {
		ProductMstDtoReader reader = new ProductMstDtoReader();
		List<ProductMstDto> values = reader.getValues();
		assertNotNull(values);
		for (ProductMstDto value : values) {
			assertNotNull(value);
			assertNotNull(value.getProductMstId());
			assertNotNull(value.getProductType());
			assertNotNull(value.getProductName());
			assertNotNull(value.getPrice());
			assertNotNull(value.getPriceUnit());
		}
	}
}
