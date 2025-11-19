// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getAuth } from "firebase/auth";
import { getFirestore } from 'firebase/firestore';
// TODO: Add SDKs for Firebase products that you want to use// https://firebase.google.com/docs/web/setup#available-libraries// Your web app's Firebase configuration
// Import the functions you need from the SDKs you needs

// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey: "AIzaSyDLdxYctqZN8LgM3tpVz5DgEJ1e3cR-p24",
  authDomain: "guidedp-39530.firebaseapp.com",
  projectId: "guidedp-39530",
  storageBucket: "guidedp-39530.firebaseapp.app",
  messagingSenderId: "54570826935",
  appId: "1:54570826935:web:fcaf6af310009bc53aa132"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);

// Initialize Firebase Authentication and get a reference to the service
const auth = getAuth(app);

// Initialize Firestore
const db = getFirestore(app);

export { app, auth, db };