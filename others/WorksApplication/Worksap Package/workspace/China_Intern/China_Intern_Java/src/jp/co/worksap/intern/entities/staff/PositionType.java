package jp.co.worksap.intern.entities.staff;

public enum PositionType {
	staff, manager, region_manager;

	public String toString() {
		switch (this) {
		case staff:
			return "staff";
		case manager:
			return "manager";
		case region_manager:
			return "region manager";
		default:
			return "";
		}
	}

	public static PositionType valueOfString(String src) {
		String raw = src.toLowerCase();
		if (raw.equals("staff")) {
			return staff;
		}

		if (raw.equals("manager")) {
			return manager;
		}

		if (raw.equals("region manager")) {
			return region_manager;
		}

		throw new IllegalArgumentException("Unknown Position Type : " + raw);
	}
}
