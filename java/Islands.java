import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;

public class Islands {

	public static Map<String, Integer> islands = new HashMap<>();
	public static Random random = new Random();

	static {
		islands.put("小豆島", 6);
		islands.put("屋久島", 6);
		islands.put("種子島", 6);
		islands.put("軍艦島", 6);
		islands.put("佐渡島", 6);
	}

	public static void main(final String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			while (islands.size()>0) {
				System.out.println("Enterで島を抽選します");
				final String in = scanner.nextLine();

				final Set<String> keys = islands.keySet();
				final String island = keys.toArray(new String[keys.size()])[random.nextInt(keys.size())];
				final int remaining = islands.get(island)-1;

				if (remaining>0)
					islands.put(island, remaining);
				else
					islands.remove(island);

				System.out.println(String.format("%sに座りましょう 残り%s席", island, remaining));
			}
		}

		System.out.println("席がなくなりました！");
	}
}

