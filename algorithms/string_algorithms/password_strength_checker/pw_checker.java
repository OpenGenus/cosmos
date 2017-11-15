public class Password {

	public static void main(String[] args) {	
		// password to check
		String password = "XmkA78Ji";
		
		System.out.println(checkPassword(password));
	}

	public static boolean checkPassword(String password) {
		boolean hasUpperLetter = false;
		boolean hasLowerLetter = false;
		boolean hasDigit = false;

		final int MIN_LENGTH = 8; // the minimum length of the password

		for (int i = 0; i < password.length(); i++) {
			if (Character.isUpperCase(password.charAt(i)))
				hasUpperLetter = true;
			if (Character.isLowerCase(password.charAt(i)))
				hasLowerLetter = true;
			if (Character.isDigit(password.charAt(i)))
				hasDigit = true;
		}
		
		if(password.length() < MIN_LENGTH)
			System.out.println("The password is to short");
		if(!hasUpperLetter) 
			System.out.println("The password doesn't have a upper case letter");
		if(!hasLowerLetter)
			System.out.println("The password doesn't have a lower case letter");
		if(!hasDigit)
			System.out.println("The password doesn't have a digit");
		
		return (hasUpperLetter && hasLowerLetter && hasDigit && password.length() >= MIN_LENGTH);

	}

}
