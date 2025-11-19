import React, { useState, useEffect } from "react";
import { getFirestore, doc, getDoc, updateDoc } from "firebase/firestore";
import axios from "axios";

function WeatherComponent() {
  const db = getFirestore();
  const [weather, setWeather] = useState(null);
  const [date, setDate] = useState('');
  const fetchDate = async () => {
    const dateDoc = await getDoc(doc(db, 'settings', 'picnicDate'));
    if (dateDoc.exists()) {
      const savedDate = dateDoc.data().date;
      setDate(savedDate);
      fetchWeather(savedDate);
    } else {
      console.log("No date found in Firestore.");
    }
  };
  useEffect(() => {
    fetchDate();
  }, [db]);
  const fetchWeather = async (selectedDate) => {
    try {
      const response = await axios.get(
        `https://api.weatherapi.com/v1/forecast.json`,
        {
          params: {
            key: 'c3266ccbc133441082834141250911',
            q: 'Richardson',
            dt: selectedDate,
          },
        }
      );
      setWeather(response.data.forecast.forecastday[0].day);
    } catch (error) {
      console.error("Error fetching weather:", error);
    }
  };
  const handleDateChange = (e) => {
    setDate(e.target.value);
  };
  const handleDateUpdate = async () => {
    try {
      await updateDoc(doc(db, 'settings', 'picnicDate'), { date });
      fetchWeather(date);
      console.log("Date updated successfully in Firestore.");
    } catch (error) {
      console.error("Error updating date:", error);
    }
  };
  return (
    <div className="p-4">
      <h2 className="mb-2 poppins-bold">Weather Forecast</h2>
      <label className="block mb-2 poppins-semibold">
        We are planning on:
        <input
          type="date"
          value={date}
          onChange={handleDateChange}
          className="p-2 w-full mt-1 mb-3"
        />
      </label>
      <button onClick={handleDateUpdate} className="py-2 px-4 mb-4 transition hover:scale-110 hover:text-gray-600">
        Update Date
      </button>
      {weather && (
        <div>
          <p>Temperature: {weather.avgtemp_f}°F</p>
          <p>Condition: {weather.condition.text}</p>
        </div>
      )}
    </div>
  );
}

export default WeatherComponent;
