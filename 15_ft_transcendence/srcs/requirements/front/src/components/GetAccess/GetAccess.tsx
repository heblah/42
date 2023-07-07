import React from "react";
import SolidFrame from '../SolidFrame/SolidFrame';
import './GetAccess.scss'


const GetAccess: React.FC = ({
	}) => {

	return (
			<SolidFrame
				frameClass="access-frame"
				txtClass="text-access"
				// onClick={ () => function to log in }
				txt2="Get Access"
				link="/Login"
			/>
	);
};

export default GetAccess;
