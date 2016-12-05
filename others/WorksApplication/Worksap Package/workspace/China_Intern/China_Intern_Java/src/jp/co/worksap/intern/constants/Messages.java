package jp.co.worksap.intern.constants;

/**
 * Constants for log messages, and other messages.
 * 
 */
public final class Messages {
	//Must not be instantiated
	private Messages(){}
	
	public static final String ERROR_CSV_NOT_FOUND = "CSV File not found";
	public static final String ERROR_READ_CSV = "CSV Cannot be Read Correctly";
	public static final String ERROR_CSV_FILE_CLOSE = "Error has occured when closing csv file";
	public static final String ERROR_PARSE_DATE = "Parsing date string failed";
	public static final String ERROR_WRITE_CSV = "Failed to Write Content as CSV File";

}
