package jp.co.worksap.intern.entities.staff;

public enum RankType {
	assistant, senior, expert, officer;

	public String toString() {
		switch (this) {
		case assistant:
			return "assistant";
		case senior:
			return "senior";
		case expert:
			return "expert";
		case officer:
			return "officer";
		default:
			return ""; 
		}
	}

	public static RankType valueOfString(String src) {
		String raw = src.toLowerCase();
		if (raw.equals("assistant")) {
			return assistant;
		}

		if (raw.equals("senior")) {
			return senior;
		}

		if (raw.equals("expert")) {
			return expert;
		}

		if (raw.equals("officer")) {
			return officer;
		}

		throw new IllegalArgumentException("Unknown Rank Type : " + raw);
	}
}
