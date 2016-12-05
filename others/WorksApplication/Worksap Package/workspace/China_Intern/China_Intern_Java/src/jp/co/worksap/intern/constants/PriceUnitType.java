package jp.co.worksap.intern.constants;

public enum PriceUnitType {
	USD, EURO,JPY, CNY;

	public String toString() {
		switch (this) {
		case USD:
			return "USD";
		case EURO:
			return "EURO";
		case JPY:
			return "JPY";
		case CNY:
			return "CNY";
		default:
			return ""; 
		}
	}

	public static PriceUnitType valueOfString(String src) {
		String raw = src.toLowerCase();
		if (raw.equals("usd")) {
			return USD;
		}

		if (raw.equals("euro")) {
			return EURO;
		}

		if (raw.equals("jpy")) {
			return JPY;
		}

		if (raw.equals("cny")) {
			return CNY;
		}

		throw new IllegalArgumentException("Unknown Price Unit Type : " + raw);
	}
}
