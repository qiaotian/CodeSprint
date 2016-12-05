package jp.co.worksap.intern;

import jp.co.worksap.intern.entities.RawCSVReaderTest;
import jp.co.worksap.intern.entities.SimpleDTOReaderTest;
import jp.co.worksap.intern.writer.SimpleStaffDTOWriterTest;

import org.junit.runner.RunWith;
import org.junit.runners.Suite;

@RunWith(Suite.class)
@Suite.SuiteClasses({ 
	RawCSVReaderTest.class, 
	SimpleDTOReaderTest.class,
	SimpleStaffDTOWriterTest.class})
public class CSVTestSuite {

}
