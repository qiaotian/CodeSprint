package jp.co.worksap.intern.writer;

import java.util.List;

/**
 * Result writer interface which output result to CSV file.
 * 
 */
public interface IResultWriter {
	
	/**
	 * Write results to output CSV file.
	 * @param result output results including header columns
	 */
	public void writeResult(List<String[]> result);
}
