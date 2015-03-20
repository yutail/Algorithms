// http://howtodoinjava.com/2012/10/09/how-hashmap-works-in-java/
// http://java.dzone.com/articles/hashmap-internal

static class Entry implements Map.Entry<K, V> {
    final K key;
    V value;
    Entry next;
    final int hash;
}



public class HashMap<K, V> {
    
    transient Entry[] table;
    
    // The method to store two different objects same array location is using LinkedList.
    // Entry class had an attribute “next”. This attribute always points to next object in chain.
    // This is exactly the behavior of LinkedList.
    public V put(K key, V value) {
        if (key == null)
            return putForNullKey(value); // Hash code for null keys is always zero, and such Entry object is always
                                         // stored in zero index in Entry[].
        int hash = hash(key.hashCode());
        int i = indexFor(hash, table.length);
        for (Entry<k , V> e = table[i]; e != null; e = e.next) {
            Object k;
            if (e.hash == hash && ((k = e.key) == key || key.equals(k))) { // To test if the value we add have the
                                                                           // same key entered before
                V oldValue = e.value;
                e.value = value;
                e.recordAccess(this);
                return oldValue;
            }
        }
        modCount++;
        addEntry(hash, key, value, i);
        return null;
    }
    
    public V get(Object key) {
        if (key == null)
            return getForNullKey();
        int hash = hash(key.hashCode());
        int i = indexFor(hash, table.length);
        for (Entry<K,V> e = table[i]; e != null; e = e.next) {
            Object k;
            if (e.hash == hash && ((k = e.key) == key || key.equals(k)))
                return e.value;
        }
        return null;
    }
    
    static int hash(int h) {
        // This function ensures that hashCodes that differ only by
        // constant multiples at each bit position have a bounded
        // number of collisions (approximately 8 at default load factor).
        h ^= (h >>> 20) ^ (h >>> 12);
        return h ^ (h >>> 7) ^ (h >>> 4);
    }
    
    /*
    ** Returns index for hash code h. To calculate exact index position for storing the Entry object.
    */
    static int indexFor(int h, int length) {
        return h & (length-1);
    }
    
    public boolean containsKey(Object key) {
        
    }
    
    public boolean containsValue(Object Value) {
        
    }
    
    public boolean isEmpty() {
        
    }
    
    public int size() {
        
    }

}