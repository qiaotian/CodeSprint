package jp.co.worksap.intern.writer;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import jp.co.worksap.intern.constants.Constants;
import jp.co.worksap.intern.entities.staff.StaffDTO;
import jp.co.worksap.intern.entities.staff.StaffDTOReader;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class SimpleStaffDTOWriterTest {

	private List<StaffDTO> staffs = null;
	private IResultWriter writer = null;
	private String fileName = "STAFF_MST.csv";
	
	@Before
	public void setup() throws IOException {
		StaffDTOReader reader = new StaffDTOReader();
		staffs = reader.getValues();
		writer = new ResultWriterImpl(
				Constants.DEFAULT_CSV_OUTPUT_FOLDER + 
				fileName);
	}

	@After
	public void clean() {
		if (staffs != null) {
			staffs.clear();
		}
	}

	@Test
	public void noTitleTest() {
		List<String[]> contents = new ArrayList<String[]>(staffs.size());
		writeContent(contents);
	}

	@Test
	public void withTitleTest() {
		List<String[]> contents = new ArrayList<String[]>(staffs.size());
		contents.add(new String[] { 
				"staff_id", 
				"name", 
				"gender", 
				"rank",
				"position",
				"supermarket_id"});
		writeContent(contents);
	}

	private void writeContent(List<String[]> contents) {
		for (StaffDTO staff : staffs) {
			String[] args = new String[] { 
					staff.getStaffId().toString(),
					staff.getName(),
					staff.getGender(),
					staff.getRank().toString(),
					staff.getPosition().toString(),
					staff.getSupermarketId().toString()
					};
			contents.add(args);
		}
		writer.writeResult(contents);
	}
}
