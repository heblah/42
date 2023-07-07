import App from './App'
import reportWebVitals from './reportWebVitals'
import React from 'react'
import './index.css'
import ReactDOM from 'react-dom/client'
import { render } from 'react-dom'

const root = ReactDOM.createRoot(document.getElementById('root') as HTMLElement)
root.render(
	//<React.StrictMode>
		<App />
	//</React.StrictMode>
)

reportWebVitals()